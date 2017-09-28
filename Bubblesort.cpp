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
long long exchanges =0;
long long comparisons =0;


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

//Bubble sort
void Bubblesort(Person** A, int r){
	for( int i = 0; i < r - 1; i++) {
		
		for (int j = r-1; j>= i+1; j--){
			comparisons++;
			if (A[j]->id < A[j - 1]->id){
				exchanges++;
				swap ( A[j],  A[j - 1]);
			}
	   }
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
	

	cout << "*** BUBBLE SORT *** " <<endl;
	
	//calling bubble sort
	Bubblesort(roster, numLines);
	   
	   
	/*for ( int k = 0; k < numLines; k++){
	
	cout << roster[k]->id << " " ;
	
	}
	cout << endl;*/

	//printing out every element in the roster array
	
	//number of comparions made in the heap sort
	cout << "Comparisons: " << comparisons << endl;

	//number of exchange of elements made in the heap sort
	cout << "Exchanges: " << exchanges << endl;

	

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