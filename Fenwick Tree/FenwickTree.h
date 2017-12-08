#ifndef FENWICKTREE_H
#define FENWICKTREE_H

class FenwickTree {
    public:
        FenwickTree(void);
        FenwickTree(const int *arr, const int n);
        ~FenwickTree(void);
        void update(const int index, const int value);
        int read(const int index);

    protected:
        int next(int index) const;
        int parent(int index) const;

    private:
        int *tree;
        int size;
};

#endif // FENWICKTREE_H
