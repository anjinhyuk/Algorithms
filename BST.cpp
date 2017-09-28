#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//Node Class
class Node {
	public:
		int key;
		Node* left;
		Node* right;
		Node(int n){
			key = n;
			left = NULL;
			right = NULL;
		}
};

//global new Node
Node* root;

//TREEINSERT METHOD
void TREEINSERT( Node* z){
	Node* y = NULL;
	Node* x = root;
	while (x != NULL){
		y = x;
		if (z->key < x->key){
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	if (y == NULL){
		root = z;
	}
	else if (z->key < y-> key){
		y->left = z;
	}
	else {
		y -> right = z;
	}
}

//INORDER METHOD
void INORDER(Node* n){
	if ( n != NULL){
		INORDER(n-> left);
		cout << n -> key << " " ;
		INORDER(n -> right);
	}
}

//PREORDER
void PREORDER(Node* n){
	if (n != NULL){
		cout << n -> key << " ";
		PREORDER(n ->left);
		PREORDER(n -> right);
	}
}

//POSTORDER
void POSTORDER(Node* n){
  if (n != NULL){
	POSTORDER(n -> left);
	POSTORDER(n -> right);
	cout << n -> key << " ";
  }
}

//PRINT METHOD
void PRINT(Node* n){
    if(n != NULL){
		cout << "Node: " << n-> key << " L: " ;
        if(n-> left == NULL){
            cout << "null ";
		}
        else{
            cout << n-> left-> key << " ";
		}
	cout <<  " R: " ;
        if(n-> right == NULL){
            cout << "null " << endl;
		}
        else{
            cout << n-> right-> key << endl;
		}
	PRINT (n-> left);
    PRINT (n -> right);
	}
}

//FIND METHOD
void FIND(int f, Node* n){
	if (n != NULL){
		if(f == n->key){
			cout << n->key << " ";
			cout << " : found" << endl;
		}
		else if (f > n->key){
			cout << n->key << " ";
			FIND(f, n -> right);	
		}
		else if (f < n->key){
			cout << n->key << " ";
			FIND(f, n -> left);	
		}
	}
	else {
		cout << " : not found" <<endl;
	}
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
	int n = stoi(tmp);
	//printing out what is stored in n
	cout << "I need to read " << n << " lines." << endl;
	//////////////////////////////////////OK

	//reading in input file as a string stream
	for (int i=0; i<n; i++) {
		//instantiate the string cmd for command variable
		string cmd;
		//reading in the file and store it to tmp
		getline(ifs, tmp);
		//store tmp to ss stringstream
		stringstream ss(tmp);
		ss >> cmd;
		//cout << tmp << endl;
		
		////////// ADD
		if (cmd == "ADD"){
			int n;
			ss >> n;
			Node* node = new Node(n);
			TREEINSERT(node);
			cout << "Adding " << n << endl;
		}
		///////// INORDER
		else if(cmd == "INORDER"){ // sub == cmd
			cout << "INORDER" << endl;
			INORDER(root);
			cout << " " << endl;
		}
		////////// CLEAR
		else if (cmd == "CLEAR"){
			//cout << "clear**********" << endl;
			root = NULL;
		////////// PRINT
		} 
		else if (cmd == "PRINT"){
			//cout << "print**********" << endl;
			PRINT(root);
		}
		////////// FIND
		else if (cmd == "FIND"){
			int n;
			ss >> n;
			cout << "Looking for " << n << "... " ;
			
			FIND(n, root);
		}
		////////// PREORDER
		else if(cmd == "PREORDER"){ // sub == cmd
			cout << "PREORDER" << endl;
			PREORDER(root);
			cout << " " << endl;
		}
		////////// POSTORDER
		else if(cmd == "POSTORDER"){ // sub == cmd
			cout << "POSTORDER" << endl;
			POSTORDER(root);
			cout << " " << endl;
		}

		//cout << ss;
	}
	return 0;
}
