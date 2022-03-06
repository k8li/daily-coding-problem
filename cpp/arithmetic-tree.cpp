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

// this is gonna have to be recursive?
// can you append NULL to a string?
string appendExp(Node* curr) {
	string exp = "";

	if (curr->right!=NULL) {
		exp = exp.append(appendExp(curr->right));
		exp = appendExp(curr->left).append(exp);
		return exp;
	}
	else {
		return curr->data;
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
};

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

	eval(appendExp(root));


	return 0;
};

