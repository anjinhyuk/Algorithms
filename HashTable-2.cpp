#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include<cmath>
#include <math.h>
#include<conio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;


 
//initializing counters
int collision = 0;
int exchanges =0;
int comparisons =0;
int recursive = 0;
int totalcollision = 0;

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
int mod;

// roster[mod];


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

	string firstfirstLine;
	getline(ifs, firstfirstLine);
	mod = stoi(firstfirstLine);

	string firstLine;
    getline(ifs, firstLine);
    numLines = stoi(firstLine);
		   
    Person** roster = new Person*[numLines];
	Person** hashtable = new Person*[mod];

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
	
	//hashtable division method

	for( int i = 0; i< mod; i++){
		hashtable[i]= 0;
	}

	for( int j = 0; j<numLines; j++){

		//PART 1 - division method
			int modulo = roster[j]->id % mod;

		//PART 2 - multiplication method
		//double A = (sqrt(5.00)-1)/2;

		//int modulo =(int)( mod*( ((roster[j]->id) * A) - (int)((roster[j]->id) * A) ));
		//PART 2

		/*cout << "Attempting to hash " <<  roster[j]->name << "at index " <<  modulo;

		if(hashtable[modulo] == 0){
			hashtable[modulo] = roster[j];
			
			cout << "... SUCCESS!" << endl;
		}
		else{
			cout << "...Ouch! Collision with "<< hashtable[modulo]->name << endl;
			collision++;
		}*/
		//////////////////////////////// PART 1 AND PART 2

		cout << "Addking " <<  roster[j]->name << "to table at index " <<  modulo;

		if(hashtable[modulo] == 0){
			vector<int> vectorline;

		vectorline.push_back(modulo);
			hashtable[modulo] = roster[j];
			
			cout << "(0 collisions)" << endl;
		}
		else{
			collision++;
			cout << "("<< collision << " collisions)" << endl;
			
		}
		totalcollision +=collision;
		collision=0;


	}

	

	//printing out every element in the roster array
	
	//number of comparions made in the heap sort
	cout << "Total Collision: " << collision << endl;
	
	
	cout << "Total Collision to resolve: " << totalcollision << endl;

	//number of exchange of elements made in the heap sort
	//cout << "Exchanges: " << exchanges << endl;

	//cout << "Recursive calls: " << recursive << endl;

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