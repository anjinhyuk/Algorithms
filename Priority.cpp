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

vector<int> A;
int numLines;
int heapSize;

//left heap
int Left(int i){
	return 2*(i);
};

//right heap
int Right(int i){
	return (2*i)+ 1;
};

//parent
int Parent(int i){
	return i/2;
};


//HEAP-MAXIMUM(A)
int HEAPMAXIMUM(){
    return A[1];
}

//MAXHEAPIFY 
void MAXHEAPIFY(int i){
	int l  = Left(i);
	int r = Right(i);
	int largest;
	
	if (l <= heapSize && A[l] > A[i]){
		largest = l;
	}

	else {
		largest = i;
	}
	
	if (r <= numLines && A[r] > A[largest]){
		largest = r; 
	}
	if (largest != i){
		swap(A[i], A[largest]);
		MAXHEAPIFY(largest);
	}
}

//HEAP-EXTRACT-MAX(A)

int HEAPEXTRACTMAX(){
   if (heapSize < 1){
	   cerr << "heap underflow" << endl;
   }
   int max;
   max = A[1];
   A[1] = A[heapSize];
   heapSize = heapSize - 1;
   MAXHEAPIFY(1);
   return max;
}

//HEAP-INCREASE-KEY(A,i, key)
void HEAPINCREASEKEY(int i, int key){
	if (key < A[i]){
		cerr << " new key is smaller than current key" << endl;
	}
	A[i] = key;
	while ( i > 1 && A[Parent(i)] < A[i]){
		swap (A[i], A[Parent(i)]);
		i = Parent(i);
	}
} 

//MAX-HEAP-INSERT(A, key)
void MAXHEAPINSERT(int key){
	heapSize = heapSize + 1;
	A.resize(heapSize+1);
	A[heapSize] = -std::numeric_limits<int>::infinity();
	HEAPINCREASEKEY(heapSize, key);
}

int _tmain(int argc, _TCHAR* argv[])
{
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
    //instantiate the string tmp
    string tmp;
    //read in lines from the input file
    getline(ifs, tmp);
    //typecast the string tmp to integer
    int numLines = stoi(tmp);
    //printing out what is stored in n
    cout << "I need to read " << numLines << " lines." << endl;
    //////////////////////////////////////OK

    //reading in input file as a string stream
    for (int i=0; i< numLines; i++) {
        //instantiate the string cmd for command variable
        string cmd;
        //reading in the file and store it to tmp
        getline(ifs, tmp);
        //store tmp to ss stringstream
        stringstream ss(tmp);
        ss >> cmd;
        //cout << tmp << endl;
        
        ////////// ENQUEUE
        if (cmd == "ENQUEUE"){
            int key;
            ss >> key;
            MAXHEAPINSERT(key);
            
            //cout << "enqueue" << key << endl;
        }
		///////// DEQUEUE
		else if (cmd == "DEQUEUE"){
			if(heapSize < 1){
				cout << "empty"<<endl;
			}else{
			 int k = HEAPEXTRACTMAX();
			 cout << k << endl;
			}
		}
		////////// PEEK
		else if( cmd == "PEEK"){
			cout << HEAPMAXIMUM() << endl;
		}

		////////// CLEAR
		else if(cmd == "CLEAR")
			heapSize = 0;
		}
	return 0;
}