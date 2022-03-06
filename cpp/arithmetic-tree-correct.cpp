//This problem was asked by Microsoft.

//Suppose an arithmetic expression is given as a binary tree. Each leaf is an integer and each internal node is one of '+', '−', '∗', or '/'.

//Given the root to such a tree, write a function to evaluate it.

//use eval() to read a string as source code.
//First create object, binary tree with nodes and leaves.
//At each node, append the left leaf to the beginning of the string, the right leaf to the end.

//let's make the assumption that every node either has two leaves or no leaf.

#include <iostream>
using namespace std;

//constructing tree
struct Node {
	string data;
	Node* left;
	Node* right;
	
	Node(string data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

double evalNode(string op, double x, double y) {
	if (op == "+") {return x + y;}
	if (op == "-") {return x - y;}
	if (op == "*") {return x * y;}
	if (op == "/") {return x / y;}

	return 0; //just in case op is invalid.
}

// this is gonna have to be recursive?
// evaluate groups as they come in.
double evalExp(Node* curr) {
	string exp = "";

	//if we are in an inner node
	if (curr->right!=nullptr) {
		return evalNode(curr->data, evalExp(curr->left), evalExp(curr->right));
	}
	
	//else we are in a leaf.
	else {
		return stod(curr->data);	//return that string as a double.
	}
	
	/*
	exp = head->data; 	//simplest case: head has no left or right.

	curr = tree;
	while (curr!= NULL) {
		if curr->right != NULL {
			exp = exp.append(curr->right->data);	//append  data of right node to
		}
		if curr->left != NULL {
			exp = (curr->left->data).append(exp);
		}
	
	curr 
	*/
}

int main() {
	
	Node* root = new Node("+");
    root->left = new Node("*");
    root->right = new Node("/");
    root->left->left = new Node("-");
    root->left->right = new Node("5");
    root->right->left = new Node("21");
    root->right->right = new Node("7");
    root->left->left->left = new Node("10");
    root->left->left->right = new Node("5");

	cout << "Value of root expression is: " << evalExp(root);


	return 0;
}

