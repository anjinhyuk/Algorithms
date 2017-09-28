// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Employee.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int numLines; //counter for loooping
	int numquery; //counter for looping the query files
	int tmpid;
	ifstream ifs; //enables reading file
	ifstream qfs; //reading query file
	int comparison = 0;
	string tmpname;
	vector<Employee*> Emp; 
	//handle exceptions
	if (argc < 2){
		cout << "Missing command-line parameter." << endl;
		return 1;
	}
	ifs.open(argv[1], ios::in);//reads the file
	qfs.open(argv[2], ios::in);//reads query file
	if (!ifs) {
		cout << "Error... check file name!" << endl;
		return 1;
	}
	
	string tmpnum;
	getline(ifs, tmpnum);
	numLines = stoi(tmpnum);
	string tmpquery;
	qfs >> numquery;
	//ifs >> numLines; //firstline
	//looping through all to print it out
	for (int i = 0; i < numLines; i++){
		string tmpjob, tmpIdString, tmpAgeString, tmpYearString;
		int tmpage, tmpyear;
		getline(ifs, tmpname, '|');
		getline(ifs, tmpIdString, '|');//saves the string in the tmpString
		tmpid = stoi(tmpIdString); //convert it into int
		getline(ifs, tmpAgeString, '|');
		tmpage = stoi(tmpAgeString);
		getline(ifs, tmpjob,'|');
		getline(ifs, tmpYearString);
		tmpyear = stoi(tmpYearString);
		Employee* emp = new Employee(tmpname);
		emp->setId(tmpid);//sets all the variable
		emp->setAge(tmpage);
		emp->setJob(tmpjob);
		emp->setYear(tmpyear);
		Emp.push_back(emp);
	}
	long double total = 0;
	int idq;
	for (int i = 0; i < numquery; i++){ //loop through all the employee
		qfs >> idq;
		for (int j = 0; j != Emp.size(); j++){
			if (Emp[j]->id == idq) { // if statement to check
				//cout << "Looking for " << idq << " Found " << Emp[j]->name << " at position " << j << " after " << j+1 << " comparisons." << endl;
				total = total + j + 1;
				break;
			}
		}
		
	}
	total = total / numquery; // for comparison
	cout << "Average number of comparisons overall : " << total << endl;
	/*for (auto p : Emp){
		p->print();
	}*/
	return 0;
}

