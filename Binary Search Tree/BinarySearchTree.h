#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BinaryNode.h"

class BinarySearchTree {
	public:
		BinarySearchTree(void);
		~BinarySearchTree(void);
		
		// checks if the tree is empty or not
		bool isEmpty(void) const;

		// returns the height of the tree
		int getHeight(void);

		// returns the number of nodes 
		int getNumberOfNodes(void) const;
		
		// adds a node 
		bool add(const int &newEntry);

		// removes a node
		bool remove(const int &anEntry);

		// checks if an item is contained in the tree
		bool contains(const int &anEntry);		
		
		// traversals
		void preorderTraverse(void); 
		void inorderTraverse(void); 
		void postorderTraverse(void);
		void levelorderTraverse(void); 
		
		// returns the number of items between a and b
		int span(const int& a, const int& b);
		
		// takes the mirror image of the tree
		void mirror(void); 

	protected:
		// deletes the given subtree
		void clearTree(BinaryNode *ptr); 

		// returns the height of a subtree 
		int heightFrom(BinaryNode *ptr);

		// finds and removes a node
		void treeRemove(BinaryNode* &ptr, const int &anEntry);

		// finds and deletes the inorder successor of a given node and then copies it's data
		void inorderSuccessor(BinaryNode* &ptr, int &itemHolder);

		// recursive preorder traversal
		void preorder(BinaryNode *ptr); 

		// recursive inorder traversal
		void inorder(BinaryNode *ptr );

		// recursive postorder traversal 
		void postorder(BinaryNode *ptr); 

		// prints out the elements in a given level recursively 
		void levelorder(BinaryNode *ptr, int h);

		// counts numbers of value in a given interval recursively 
		int spanTree(BinaryNode *ptr, const int &a, const int &b); 

		// takes the mirror of the tree recursively	
		void mirrorTree(BinaryNode *ptr);

	private:
		BinaryNode *root;
		int treeSize;
} ;
#endif //BINARYSEARCHTREE_H
