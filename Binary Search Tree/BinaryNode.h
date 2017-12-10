#ifndef BINARYNODE_H
#define BINARYNODE_H

class BinaryNode {
	public:
		BinaryNode(void);
		BinaryNode(const BinaryNode& obj);
		int getItem(void);
		void setItem( const int given);

		BinaryNode* &getLeft(void);
		BinaryNode* &getRight(void);
		
		void setLeft(BinaryNode *givenPtr); 
		void setRight(BinaryNode *givenPtr);

	private:	
		BinaryNode *left, *right;
		int item;
};

#endif // BINARYNODE_H 
