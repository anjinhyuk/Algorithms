#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include<cmath>
#include <math.h>

using namespace std;

//creating Person class
class Person {
public:
    string name;
    string id;
    string age;
    string job;
    string hireyear;
};

int _tmain(int argc, _TCHAR* argv[])
{
    //opening roster.txt
    ifstream ifs;
  

    

    //This is how you can check if the user
    //forgot to include the filename. Basically you're just
    //checking the length of the argv array. (The length of
    //argv is stored in the argc variable.)

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
    int numLines;
    string firstLine;
    getline(ifs, firstLine);
    numLines = stoi(firstLine);

   
    Person** roster = new Person*[numLines];

    //cout << "hellow" << endl;
   
    //storing every Person objects into the roster array
    for (int i=0; i<numLines; i++) {
        Person* b = new Person();
        getline(ifs, b->name, '|');
        getline(ifs, b->id, '|');
        getline(ifs, b->age, '|');
        getline(ifs, b->job, '|');
        getline(ifs, b->hireyear);
        roster[i] = b; //here *b means "give me the object that is stored in the memory address referred to in variable b"
        //cout << roster[i].age << endl;
    }
	//initialize count variable
	int count = 0;
	//initialize compare variable
	int compare = 0;

	//keep doing the selection sort until all elements are from smallest to largest
		
        cout << "*** SELECTION SORT *** " <<endl;


        for (int i=0; i < numLines-1; i++){
			
			string min = roster[i]->id;
			
			int min1 = stoi(min);

			int minIndex = i;
			
			for	(int j = i; j < numLines; j++){
				//counting comparisons
				compare++;
				if (stoi(roster[j]->id) < min1){
					
					min1 = stoi(roster[j]->id);

					minIndex = j;
				}

				
		
			}

			swap(roster[minIndex], roster[i]);
			/*Person* tmp = roster[minIndex] ;
			roster[minIndex] = roster[i];
			roster[i] = tmp;*/

		//counting exchanges
		 count ++;
		 
		//printing out every element in the roster array
		for (int a =0; a<numLines; a++){

				cout << roster[a]->id ;
			
				}
				cout << endl;
			
		
		}


		cout << "comparisons: " << compare << endl;
		cout << "exchanges: " << count << endl;
		
		


		ofstream ros;
		ros.open("n1.txt");
		
		for (int i=0; i<100; i++) {
			ros << i << roster[i]->name << endl;
			ros << i << roster[i]->id << endl;
			ros << i << roster[i]->age << endl;
			ros << i << roster[i]->job << endl;
			ros << i << roster[i]->hireyear << endl;
			
		}
		ros.close(); //this is important






    return 0;

}