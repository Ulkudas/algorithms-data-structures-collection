#ifndef SORTING_H
#define SORTING_H

#define swap(aa, bb) { int temp = aa; aa = bb; bb = temp; } // swaps two integers

void selectionSort(int* arr, int n);

void quickSort(int *arr, int n);
void quickSort_aux(int *arr, const int begin, const int end);

// Carries the pivot element to the place where it should be in the sorted array  
int partition(int *arr, const int begin, const int end);

void mergeSort(int *arr, int n);
void mergeSort_aux(int *arr, const int begin, const int end); 

// Creates a bigger sorted array from two separate sorted arrays (in descending order) 
void merge(int *arr, const int begin, const int end);

#endif //SORTING_H
