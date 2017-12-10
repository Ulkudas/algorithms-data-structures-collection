#include "BinaryNode.h"
#include <cstdio>

BinaryNode::BinaryNode(void) {
    right = NULL;
    left = NULL; 
}

BinaryNode::BinaryNode(const BinaryNode& obj) {
    left = obj.left;
    right = obj.right; 
    item = obj.item;
}

int BinaryNode::getItem(void) {
    return item;
}

void BinaryNode::setItem(const int given) {
    item = given;
}

BinaryNode* &BinaryNode::getLeft(void) {
    return left;    
}

BinaryNode* &BinaryNode::getRight(void) {
    return right;    
}

void BinaryNode::setLeft(BinaryNode *givenPtr) {
    left = givenPtr;    
}

void BinaryNode::setRight( BinaryNode *givenPtr)
{
    right = givenPtr ;    
}
