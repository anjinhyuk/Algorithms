#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include<cmath>
#include <math.h>

using namespace std;

int compare = 0;

//creating Person class
class Person {
public:
    string name;
    int id;
    string age;
    string job;
    string hireyear;
};

int numLines;

void merge(Person** A, int p, int q, int r){
	
	int n1 = q - p + 1;;
	int n2 = r - q;;
		
	Person** L = new Person*[n1+1];
	Person** R = new Person*[n2+1];
	
	Person* abc = new Person();

	for ( int i = 0; i < n1; i++ ){
		L[i] = A[p+i];
	};

	for ( int j = 0; j < n2; j++ ){
		R[j] = A[q+j+1];
	};
	
	abc->id = 99999999999999999;
	L[n1] = abc;
	R[n2] = abc;
	int i = 0;
	int j = 0;
	for ( int k = p; k <= r; k++){
		compare++;
		if (L[i]->id <= R[j]->id){
			A[k] = L[i];
			i++;
		}
		else{
			A[k] = R[j];
			j++;
		}
	}	
	for ( int k = 0; k < numLines; k++){
	cout << A[k]->id << " " ;
	
	}
	cout << endl;
}

//initialize compare variable



void mergesort(Person** A, int p, int r){
	
	if (p < r){
		int q =  (p+r)/2;
		mergesort(A, p, q);
		mergesort(A, q+1, r);
		merge(A, p, q, r);
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
	
	//keep doing the merge sort until all elements are from smallest to largest
	cout << "*** MERGE SORT *** " <<endl;
		//printing out every element in the roster array
	mergesort(roster, 0, numLines-1 );
	
	cout << "comparisons: " << compare << endl;

	ofstream ros;
	ros.open("n1.txt");
		
		for (int i=0; i<100; i++) {
			ros << roster[i]->name << "|" << " ";
			ros << roster[i]->id << "|" << " ";
			ros << roster[i]->age << "|" << " ";
			ros << roster[i]->job << "|" << " ";
			ros << roster[i]->hireyear << "|" << endl;
			
		}
	ros.close(); //this is important*/
		
    return 0;
}