/**
	#author: Ulkudas
**/

#ifndef AVL_H
#define AVL_H

#include <iostream>

using namespace std;

class AVL {
	private:
		struct Node {
			string item;
			Node *left;
			Node *right;
		}; 
	
	public:
		AVL(void);
		~AVL(void);
	
		bool isEmpty(void) const;
		void add(const string given);
		void search(const string given);
		void preorderTraverse(void);
		void inorderTraverse(void); 	

	protected:
		void rightRotation(Node* &current);
		void leftRotation(Node* &current);
		void printSuggestions(Node *current, const string given, bool &flag);
		int findHeight(Node* current);
		void destructTree(Node* &current);
		void preorder(Node *current);
		void inorder(Node *current);

	private:
		Node *root;
};

#endif
