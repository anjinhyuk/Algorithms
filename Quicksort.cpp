#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include<cmath>
#include <math.h>
#include<conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

//initializing counters
int compare = 0;
int exchanges =0;
int comparisons =0;
int recursive = 0;

//creating Person class
class Person {
public:
    string name;
    int id;
    string age;
    string job;
    string hireyear;
};

//initializing variables to store array lengths
int numLines;
int length;

// partitioning the array
int Partition(Person**A, int p, int r){
	int x = A[r]->id;
	int i = p - 1;
	
	for(int j = p ; j <= (r-1); j++){
		comparisons++;
		if (A[j]->id < x){
			i = i + 1;
			swap(A[i], A[j]);
			exchanges++;
			for ( int k = 0; k < numLines; k++){
			cout << A[k]->id << " " ;
			}
			cout << endl;
			}
	
	}
	for ( int k = 0; k < numLines; k++){
	cout << A[k]->id << " " ;
	}
	cout << endl;
	swap(A[i+1], A[r]);
	exchanges++;
	for ( int k = 0; k < numLines; k++){
	
	cout << A[k]->id << " " ;
	
	}
	cout << endl;
	return (i+1 );

}

//randomized partition


int RandomizedPartition(Person**A, int p, int r){
	
	srand (time(NULL));	//seed the random number
						//algorithm with the current
						//system clock timestamp.
		//limit our numbers to 0..n-1
	int i = rand() % r;
	//cout << r << endl;
	swap(A[r], A[i]);
	return Partition(A, p, r);
}

//quicksort

void Quicksort(Person**A, int p, int r){
	int q;
	if(p < r){
		 q = Partition(A, p, r);
		
			Quicksort(A, p, q-1);
			 recursive++;
			Quicksort(A, q + 1, r);
			 recursive++;
	};
}

//tail quicksort
void tailQuicksort(Person**A, int p, int r){
	while (p < r){
		int q = Partition(A, p, r);
		tailQuicksort(A, p, q -1); 
		recursive++;
		p = q + 1;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
    //opening roster.txt
    ifstream ifs;
  
	//roster file exception handling
    if (argc < 2) {
        cout << "missing command line parameter!" << endl;
        exit(1);
    }
	ifs.open(argv[1], ios::in);
    if (!ifs) {
        cout << "file not found. How sad." << endl;
        exit(1);
    }
	    
    //Roster lines
    
    string firstLine;
    getline(ifs, firstLine);
    numLines = stoi(firstLine);
	   
    Person** roster = new Person*[numLines];

    //storing every Person objects into the roster array
    for (int i=0; i<numLines; i++) {
        Person* b = new Person();
        getline(ifs, b->name, '|');
		string temp; 
        getline(ifs, temp, '|');
		b->id = stoi(temp);
        getline(ifs, b->age, '|');
        getline(ifs, b->job, '|');
        getline(ifs, b->hireyear);
        roster[i] = b; //here *b means "give me the object that is stored in the memory address referred to in variable b"
       // cout << roster[i]->id << endl;
    }
	

	cout << "*** QUICK SORT *** " <<endl;
	
	Quicksort(roster, 0, numLines-1);

	//printing out every element in the roster array
	
	//number of comparions made in the heap sort
	cout << "Comparisons: " << comparisons << endl;

	//number of exchange of elements made in the heap sort
	cout << "Exchanges: " << exchanges << endl;

	cout << "Recursive calls: " << recursive << endl;

	//writing files to a txt file
	ofstream ros;
	ros.open("n1.txt");
		
		for (int i=0; i< numLines ; i++) {
			ros << roster[i]->name << "|" << " ";
			ros << roster[i]->id << "|" << " ";
			ros << roster[i]->age << "|" << " ";
			ros << roster[i]->job << "|" << " ";
			ros << roster[i]->hireyear << "|" << endl;
			
		}
	ros.close(); //this is important*/
		
    return 0;
}