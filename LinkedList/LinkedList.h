/**
	@author : Ulkudas
**/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <bits/stdc++.h>

using namespace std;

template<class type> 
class LinkedList {
	public:
		LinkedList(void);
		~LinkedList(void);
		LinkedList(const LinkedList &obj);

		bool isEmpty(void) const;
		int getSize(void) const;

		void add(const type newItem, const int index);
		void remove(const int index);
		type get(const int index);
		void print(void) const;

	private:
		struct Node{
			type item;
			Node *next;
		};
		
		int size;
		Node *head;
};


// constructor
template<class type> 
LinkedList<type>::LinkedList(void) : head(NULL), size(0) {}

// destructor
template<class type>
LinkedList<type>::~LinkedList(void) {
	while(!isEmpty())
		remove(0);
}

// copy constructor
template<class type>
LinkedList<type>::LinkedList(const LinkedList &obj) {
	delete this;

	size = obj.size;
	head = obj.head;
	
	if (obj.head != NULL) {
		Node *cur = obj.head->next;
		Node *holder = head;
		while (cur != NULL) {
			holder->next = new Node;
			holder->next->item = cur->item;
			holder = holder->next;
			cur = cur->next;
		}
	}

}

// checks if the list is empty
template<class type> 
bool LinkedList<type>::isEmpty(void) const {
	return !size;	
}

// returns the size
template<class type>
int LinkedList<type>::getSize(void) const {
	return size;
}

// inserts a new entry into specified index
template<class type>
void LinkedList<type>::add(const type newItem, const int index) {
	if (index > size || index < 0)
		throw "LinkedList<> add(): Index out of bounds!";
		
	++size;
	
	Node *tempPtr = new Node;
	tempPtr->item = newItem;

	if (index == 0) {
		if (head == NULL) {
			head = tempPtr;
			head->next = NULL;
		}
		else {
			tempPtr->next = head;
			head = tempPtr;
		}
	}
	else {
		Node *cur = head;
		
		for (int i = 0; i < index - 1; ++i)
			cur = cur->next;
		
		tempPtr->next = cur->next;
		cur->next = tempPtr;
	}
}

// removes the entry at the given index
template<class type>
void LinkedList<type>::remove(const int index) {
	if (index >= size || index < 0)
		throw "LinkedList<> remove(): Index out of bounds!";
	
	--size;

	if (index == 0) {
		Node *tempPtr = head->next;	
		delete head;
		head = tempPtr;
	}
	else {	
		Node *cur = head;
		
		for (int i = 0; i < index - 1; ++i)
			cur = cur->next;

		Node *tempPtr = cur->next;

		cur->next = cur->next->next;

		delete tempPtr;
	}
}


// returns the entry at the specified index
template<class type>
type LinkedList<type>::get(const int index) {
	if (index >= size || index < 0)
		throw "LinkedList<> get(): Index out of bounds!"; 
	
	Node *cur = head;
	for (int i = 0; i < index; ++i)
		cur = cur->next;
	
	return cur->item;
}

// prints out the list from beginning to end
template<class type>
void LinkedList<type>::print(void) const {
	Node *cur = head;

	while (cur != NULL) {
		cout<< cur->item << " ";
		cur = cur->next;
	}
}

/**
	in order to catch exceptions:

	try {
		statement ...
	} catch(const char *message) {
		cerr<<message <<endl;
	}
**/


#endif // LINKEDLIST_H
