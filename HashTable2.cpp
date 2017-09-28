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

int alphabets[51];
string alphabetstring = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";


int lengthofstring =alphabetstring.size();


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

int index(string s){
	int size = s.size();
	int index= 0;
	for (int i =0; i< size; i++){
	index += s[i] ;
	
	}
	return index;


};


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
	vector<vector<Person*>> ArrayMan;
	ArrayMan.resize(mod);

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
	
	string ss;
    getline(ifs, ss);
    getline(ifs, ss);
	int sear = stoi(ss);

	string* name;
	name = new string [sear];
	for (int i =0; i< sear; i++){
		 getline(ifs, name[i]);
	}

	//hashtable division method

	for( int i = 0; i< mod; i++){
		hashtable[i]= 0;
	}

	//hashing the name
	for( int j = 0; j<numLines; j++){

		int hash = index(roster[j]->name);
		int modulo = hash % mod;
		//push back to vector
		ArrayMan[modulo].push_back(roster[j]);
		//collision counter
		int num = ArrayMan[modulo].size()-1;
		cout << "Adding " <<  roster[j]->name << "to table at index " <<  modulo << "( " << num << " collisions)" << endl;

		
		
		
	


	}
	int total = 0;
	//hash 
	for(int i= 0; i< sear; i++){
			int hash = index(name[i]);
			int modulo = hash % mod;
			for(int j = 0; j< ArrayMan[modulo].size(); j++){
				if (name[i] == ArrayMan[modulo].at(j)->name){
				collision++;
				cout << "Found "<<ArrayMan[modulo].at(j)->name << "after " << j << " collisions at index" << modulo << "in the hashtable" << endl;
				total +=j;
				
				
				
				}
			
			
			
			
			
			}
		
	
	
	
	
	
	
	}






	//printing out every element in the roster array
	
	//number of comparions made in the heap sort
	//cout << "Total Collision: " << collision << endl;
	
	
	cout << "Total Collision to resolve: " << total << endl;

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