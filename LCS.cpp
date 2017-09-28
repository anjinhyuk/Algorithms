// Hou.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include<cmath>
#include <math.h>
#include<conio.h>
#include<limits>

using namespace std;

//TWO DIMENSIONAL ARRAY CLASS
class TWODIntArray {
private:
	int* data;
	int X, Y;
public:
	TWODIntArray(int x, int y) {
		X = x;
		Y = y;
		data = new int[x*y];
	}

	TWODIntArray() {
		delete[] data;
	}

	int get(int x, int y) {
		return data [y*X + x];
	}

	void set(int x, int y, int value) {
		data[y * X + x] = value;
	}

	
};



	TWODIntArray* B;
	TWODIntArray* C;

	string line1;
	string line2;

	int TOP = 0; 
	int SIDE = 1;
	int LEFT = 2;

	
	void LCSLENGTH(){
		int m = line1.length();
		int n = line2.length();
		TWODIntArray* b = new TWODIntArray(m+1, n+1);
		TWODIntArray* c = new TWODIntArray(m+1, n+1);
		for( int i = 0; i <= m; i++){
			c->set(i, 0,0);
		}
		for(int j =0; j <= n; j++){
			c->set(0, j, 0);
		}
		
		for(int i =1; i<= m; i++){
			for(int j = 1; j<= n; j++){
				
				if(line1[i- 1] == line2[j- 1]){
					c->set(i, j, c->get(i-1, j- 1)+1);
					b->set(i, j, SIDE );
				}
				else if(c->get( i-1, j) >= c->get(i, j- 1)){
					c->set( i, j, c->get(i- 1, j));
					b->set(i, j, TOP );
				}
				else {
					c->set(i, j,c->get(i,j - 1));
					b->set(i, j, LEFT );	
				}
			
			
			}
		}

		B = b;
		C = c;
			
	}

	//PRINTLCS METHOD
	void PrintLCS(int i, int j){

		if (i == 0 || j == 0){
			return;
		}
		if ( B->get(i, j) == SIDE ){
			PrintLCS( i-1, j- 1);
			cout << line1[i - 1];
		}

		else if ( B->get( i, j) == TOP ){
			PrintLCS( i- 1, j);
		} 
		else {
			PrintLCS(i, j- 1);
		}
	}


int _tmain(int argc, _TCHAR* argv[])
{
	//Reading in file
	 ifstream ifs;
    //file exception handling
    if (argc < 2) {
        cout << "missing command line parameter!" << endl;
        exit(1);
    }
    ifs.open(argv[1], ios::in);
    if (!ifs) {
        cout << "file not found. How sad." << endl;
        exit(1);
    }
	//read in first line
	getline(ifs, line1);
	//read in second line
	getline(ifs, line2);

	//Print out line 1 and line 2 outputs
	cout << "String X: " << line1 << endl;
	cout << "String Y: " << line2 << endl;

	//LCSLENGTH METHOD
	LCSLENGTH();
	cout << "LCS: ";
	
	//PRINT OUT LCS METHOD
	PrintLCS(line1.length(),line2.length());

	cout<< endl;

	return 0;
}

