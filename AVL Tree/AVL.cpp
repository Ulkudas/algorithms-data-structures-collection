/**
	@author: Ulkudas
**/

#include "AVL.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

AVL::AVL(void) {
	root = NULL;
}

AVL::~AVL(void){
	destructTree(root);	
}

// recursive destructor
void AVL::destructTree(Node *&current) {
	if (current == NULL)
		return;

	destructTree(current->left);
	destructTree(current->right);
	
	current->left = current->right = NULL;
	delete current;
}

// checks if the tree is empty		
bool AVL::isEmpty(void) const {
	return root == NULL;
}

// inserts an item
void AVL::add(const string given) {
	Node *current = root;
	Node *preTemp = NULL;

	Node *newNode = new Node;
	newNode->right = NULL;
	newNode->left = NULL;
	newNode->item = given;
	
	Node *imbalanced = NULL;
	Node *predecessor = NULL;

	if (isEmpty()){
		root = newNode;
		return;
	}

	while (current != NULL){	
		if (current->item > given) {	
			if (findHeight(current->left) > findHeight(current->right)) {
				predecessor = preTemp; 
				imbalanced = current;
			}

			if (current->left == NULL) {
				current->left = newNode;
				break;
			}
			
			preTemp = current;
			current = current->left;	
		}
		else if (current->item < given) {
			if (findHeight(current->right) > findHeight(current->left)) {
				predecessor = preTemp;
				imbalanced = current;
			}

			if (current->right == NULL) {
				current->right = newNode;
				break;
			}
			
			preTemp = current;
			current = current->right;
		}
	}
	

	// if there is an imbalance
	if (imbalanced != NULL) {
		// the struggle is real to get a reference
		Node* &tmpPtr = (predecessor == NULL)? root : (given < predecessor->item)? predecessor->left : predecessor->right;
		
		if (given < tmpPtr->item) {
			if (given < tmpPtr->left->item) // single right rotation
				rightRotation(tmpPtr);
			else { // double left right rotation
				leftRotation(tmpPtr->left);
				rightRotation(tmpPtr);
			}
		}

		if (given > tmpPtr->item) {
			if (given > tmpPtr->right->item) // single left rotation
				leftRotation(tmpPtr);
			else {
				rightRotation(tmpPtr->right); // double right left rotation
				leftRotation(tmpPtr);
			}
		}
	}

}



// return the height 
int AVL::findHeight(Node* current) {
	if (current == NULL)
		return 0;

	return 1 + max(findHeight(current->left), findHeight(current->right));
}


// searches an item in the tree, if not found prints out suggestions
void AVL::search(const string given) {
	if (isEmpty()) {
		cout<<" Not found!" <<endl;
		return;
	}
		
	Node *current = root;

	while (current != NULL) {
		if (current->item == given) {
			cout<<"Found!"<<endl;
			return;
		}
		
		if (current->item > given)
			current = current->left;
		else 
			current = current->right;
	}

	bool flag = true;
	
	cout<<" Not found!\n Some suggestions: ";

	printSuggestions(root, given, flag);

	if (flag)
		cout <<"No suggestions for this word!";
	cout<<endl;
}

// prints out suggestions
void AVL::printSuggestions(Node *current, const string given, bool &flag) {
	if (current == NULL) 
		return;
	
	for (int i = 0; i < min(given.size(), current->item.size()) && given[i] == current->item[i]; ++i)
		if (i >= given.size()/2) {
			cout<< current->item << " "; 
			flag = false;
			break;
		}
	
	printSuggestions(current->left, given, flag);
	printSuggestions(current->right, given, flag);	
}


// rotation functions
void AVL::rightRotation(Node* &current) {
	Node *temp = current;
	Node *tempRight = current->left->right;
	current = current->left;
	current->right = temp;
	current->right->left = tempRight;
}

void AVL::leftRotation(Node* &current) {
	Node *temp = current;
	Node *tempLeft = current->right->left;
	current = current->right;
	current->left = temp;
	current->left->right = tempLeft;
}


// traversals
void AVL::preorderTraverse(void) { // for checking the current structure of the tree
	cout<<"preorder traverse: ";
	preorder(root);
	cout<<endl;
}

void AVL::preorder(Node *current) {
	if (current == NULL)
		return;

	cout<<current->item<<" ";
	preorder(current->left);
	preorder(current->right);
}

void AVL::inorderTraverse(void) {
	cout <<"inorder traverse: ";
	inorder(root);
	cout<<endl;
}

void AVL::inorder(Node *current) {
	if (current == NULL)
		return;
	
	inorder(current->left);
	cout<<current->item<<" ";
	inorder(current->right);
}







