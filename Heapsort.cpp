#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include<cmath>
#include <math.h>
#include<conio.h>

using namespace std;

//initializing counters
int compare = 0;
int exchanges =0;
int comparisons =0;

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


//left heap
int Left(int i){
	return 2*(i + 1);
};

//right heap
int Right(int i){
	return (2*i)+ 1;
};

//heap building, comparing and swapping
void Maxheapify(Person**A, int i){
	int l  = Left(i);
	int r = Right(i);
	int largest;
	
	if (l <= length && A[l]->id > A[i]->id){
		largest = l;
	}

	else {
		largest = i;
	}
	
	if (r <= length && A[r]->id > A[largest]->id){
		largest = r; 
	}
	comparisons+=5;
	if (largest != i){
		swap(A[i], A[largest]);
		exchanges++;
		Maxheapify(A, largest);
	}

	/*for ( int k = 0; k < numLines; k++){
	
	cout << A[k]->id << " " ;
	
	}
	cout << endl;*/


}

//build the whole heap
void Buildmaxheap(Person **A){
	length = numLines-1;
	for( int i = (numLines-1)/2; i >= 0; i--){
		Maxheapify(A, i);
	};
}


void Heapsort(Person **A){
	//for ( int k = 0; k < numLines; k++){
	
	//cout << A[k]->id << " " ;
	
	//}
	cout << endl;
	Buildmaxheap(A);
	for( int i = numLines-1; i > 0; i--){
		//for ( int k = 0; k < numLines; k++){
	
		//cout << A[k]->id << " " ;
	
		//}
		cout << endl;
		swap(A[0], A[i]);
		exchanges++;
		length = length - 1;
		Maxheapify(A, 0);

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
	

	cout << "*** HEAP SORT *** " <<endl;
	
	Heapsort(roster );

	//printing out every element in the roster array
	for ( int k = 0; k < numLines; k++){
	
	cout << roster[k]->id << " " ;
	
	}
	cout << endl;

	//number of comparions made in the heap sort
	cout << "comparisons: " << comparisons << endl;

	//number of exchange of elements made in the heap sort
	cout << "exchanges: " << exchanges << endl;

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