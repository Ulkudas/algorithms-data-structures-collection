#include "FenwickTree.h"
#include <cstring>
#include <cstdio>
FenwickTree::FenwickTree(void) {
    size = 0;
    tree = NULL;     
}

FenwickTree::FenwickTree(const int *arr, const int n) {
    // giving it 5 element margin to prevent errors
    tree = new int[n+5]; 
    size = n;
    
    memset(tree, 0, (n+5)*sizeof(int));

    for (int i = 0; i < n; ++i)
        update(i, arr[i]);
}

FenwickTree::~FenwickTree(void) {
    if (tree) delete tree;
}

void FenwickTree::update(const int index, const int newValue) {
    int current = index + 1;
    
    int addition = newValue - (read(index) - read(index - 1));

    while (current <= size) {
        tree[current] += addition;
        current = next(current);
    }
}

int FenwickTree::read(const int index) {
    int sum = 0, current = index + 1;

    while (current > 0) {
        sum += tree[current];
        current = parent(current);
    }

    return sum;
}

inline int FenwickTree::next(const int index) const {
    return index + (index & -index);
}

inline int FenwickTree::parent(const int index) const {
    return index - (index & -index);
}


