#include "BinarySearchTree.h"
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

BinarySearchTree::BinarySearchTree(void) {
	root = NULL;
	treeSize = 0;
}

BinarySearchTree::~BinarySearchTree(void) {
	clearTree(root);
}

// deletes the given subtree
void BinarySearchTree::clearTree(BinaryNode *ptr) {
	if (ptr == NULL)
		return;

	clearTree(ptr->getLeft());
	ptr->setLeft(NULL);

	clearTree(ptr->getRight()); 
	ptr->setRight(NULL);

	--treeSize;
	delete ptr;
}

// checks if the tree is empty or not
bool BinarySearchTree::isEmpty(void) const {
	return treeSize == 0;
}

// returns the height of the tree
int BinarySearchTree::getHeight(void) {
	return heightFrom(root);
}

// returns the height of a subtree
int BinarySearchTree::heightFrom(BinaryNode *ptr) {
	if (ptr == NULL)
		return 0;
	
	return 1 + max(heightFrom(ptr->getLeft()), heightFrom(ptr->getRight())); 	
}

// returns the number of 
int BinarySearchTree::getNumberOfNodes(void) const {
	return treeSize;
}

// inserts an item
bool BinarySearchTree::add(const int& newEntry) {
	if (contains(newEntry))
		return 0;
	
	++treeSize; 

	BinaryNode *newPtr = new BinaryNode; 
	newPtr->setItem(newEntry); 
	
	if (root == NULL) { // if the tree is empty  
		root = newPtr;
		return 1;
	}
	
	BinaryNode *holder = root;

	while (holder != NULL) {
		if (holder->getItem() > newEntry) {
			if (holder->getLeft() == NULL) {
				holder->setLeft(newPtr);
				return 1; 
			}
			else 
				holder = holder->getLeft();
		}
		else {
			if (holder->getRight() == NULL) { 
				holder->setRight(newPtr);
				return 1;
			}
			else 
				holder = holder->getRight();
		}
	}
}

// removes an item 
bool BinarySearchTree::remove(const int& anEntry) {
	if (!contains(anEntry))
		return 0;
	
	treeRemove(root, anEntry); 

	--treeSize;
	
	return 1;
}

// finds and removes a node 
void BinarySearchTree::treeRemove(BinaryNode* &ptr, const int &anEntry) {
	if (ptr == NULL) 
		return;
	
	if (ptr->getItem() == anEntry) {
		BinaryNode *temp;
		if (ptr->getLeft() == NULL && ptr->getRight() == NULL) {
			delete ptr;
			ptr = NULL;
		}
		else if (ptr->getRight() == NULL) {
			temp = ptr;
			ptr = ptr->getLeft();
			temp->setLeft(NULL);
			delete temp;
		}
		else if (ptr->getLeft() == NULL) {
			temp = ptr;
			ptr = ptr->getRight();
			temp->setRight(NULL);
			delete temp;
		}
		else {
			int leftMostItem;
			inorderSuccessor(ptr->getRight(),leftMostItem); 	
			ptr->setItem(leftMostItem);
		}
	}

	else if (ptr->getItem() > anEntry)
		treeRemove(ptr->getLeft(), anEntry);
	else 
		treeRemove(ptr->getRight(), anEntry); 

}

// finds and deletes the inorder successor of a given node and then returns it's value
void BinarySearchTree::inorderSuccessor(BinaryNode* &ptr, int &itemHolder) {
	if (ptr->getLeft() == NULL) {
		itemHolder = ptr->getItem();
		BinaryNode *tempPtr = ptr;
		ptr = ptr->getRight();
		tempPtr->setRight(NULL);
		delete tempPtr;
	}
	else 
		inorderSuccessor(ptr->getLeft(), itemHolder); 
}

// checks if an item is contained in the tree
bool BinarySearchTree::contains(const int &anEntry) {
	BinaryNode *holder = root;

	while (holder != NULL) {
		if (holder->getItem() == anEntry)
			return 1;
		
		if (holder->getItem() > anEntry)
			holder = holder->getLeft();
		else 
			holder = holder->getRight();
	}

	return 0;
}

// prints out the preorder traversal of the tree
void BinarySearchTree::preorderTraverse(void) {
	preorder(root);
	cout<<endl;
}

// recursive preorder traversal
void BinarySearchTree::preorder(BinaryNode *ptr) {
	if (ptr == NULL)
		return;
	
	cout<<ptr->getItem()<<" ";

	preorder(ptr->getLeft());
	preorder(ptr->getRight()); 
}

// prints out the inorder traversal of the tree
void BinarySearchTree::inorderTraverse(void) {
	inorder(root);
	cout<<endl;
}

// recursive inorder traversal
void BinarySearchTree::inorder(BinaryNode *ptr) {
	if (ptr == NULL)
		return;

	inorder(ptr->getLeft());
	
	cout<<ptr->getItem()<<" ";
	
	inorder(ptr->getRight());
}

// prints out the postorder traversal of the tree
void BinarySearchTree::postorderTraverse(void) {
	postorder(root);
	cout<<endl;
}

// recursive postorder traversal 
void BinarySearchTree::postorder(BinaryNode *ptr) {
	if (ptr == NULL)
		return;

	postorder(ptr->getLeft());
	postorder(ptr->getRight()); 

	cout<<ptr->getItem()<<" ";
}

// prints out the values for each level respectively, starting from the root  
void BinarySearchTree::levelorderTraverse(void) {
	int height = getHeight();

	for (int i = 1; i <= height; ++i)
		levelorder(root, i);

	cout<<endl;
}

// prints out the elements on the given level recursively 
void BinarySearchTree::levelorder(BinaryNode *ptr, int h) {
	if (ptr == NULL) 
		return;
	
	if (--h == 0)
		cout<<ptr->getItem()<<" ";
	
	levelorder(ptr->getLeft(), h);
	levelorder(ptr->getRight(), h);
}

// returns number of values in the given interval, inclusive
int BinarySearchTree::span(const int& a, const int& b) {
	return spanTree(root, a, b);
}

//	counts numbers of value in the given interval recursively 
int BinarySearchTree::spanTree(BinaryNode *ptr, const int& a, const int& b) {
	if (ptr == NULL)
		return 0;
	
	int s = (ptr->getItem() >=a && ptr->getItem() <= b);

	return s + spanTree(ptr->getLeft(), a, b) + spanTree(ptr->getRight(), a, b);
}

// takes the mirror image of the tree by swapping every single left child and right child 
void BinarySearchTree::mirror(void) {
	mirrorTree(root);
}

// takes the mirror image recursively
void BinarySearchTree::mirrorTree(BinaryNode *ptr) {
	if (ptr == NULL)
		return;

	mirrorTree(ptr->getLeft());
	mirrorTree(ptr->getRight()); 

	BinaryNode *temp = ptr->getLeft();
	ptr->setLeft(ptr->getRight());
	ptr->setRight(temp);
}
