#include "sorting.h"

void selectionSort(int* arr, int n) {
	int maxIndex; 

	for (int i = 0; i < n; ++i) {
		maxIndex = i;

		for (int j = i+1; j < n; ++j)
			maxIndex = (arr[j] > arr[maxIndex]) ? j : maxIndex;
		
		swap(arr[maxIndex], arr[i]);
	}
}

void quickSort(int* arr, int n) {
	quickSort_aux(arr, 0 , n-1);
}

void quickSort_aux(int* arr, const int begin, const int end) {
	if ( begin >= end)
		return;

	int place = partition(arr, begin, end);
	
	quickSort_aux(arr, begin, place - 1); 
	quickSort_aux(arr, place + 1, end);
}

int partition(int* arr, const int begin, const int end) {
	int pivot = arr[begin];
    int i = begin + 1;
    int j = end;

    if (i == j) { // if there are only two elements 
        if (arr[begin] <= arr[begin+1]) {
            swap(arr[begin], arr[begin+1]);
            return begin+1;
        }

		else 
			return begin;
    }
 
    while (j > i) {
		while (arr[j] <= pivot && j > begin) --j;
        
		while (arr[i] > pivot && i < end) ++i;

		if (j > i) swap(arr[i], arr[j]);
	}

   	swap(arr[j], arr[begin]);
	
    return j;
}

void mergeSort(int* arr, int n) {
	mergeSort_aux(arr, 0, n-1);
}

void mergeSort_aux(int *arr, const int begin, const int end) {
	if (begin >= end)  // if there's only 1 element - no need to change 
		return;
	
	int mid = (begin + end)/2 ;

	mergeSort_aux(arr, begin, mid); 
	mergeSort_aux(arr, mid+1, end);
	merge(arr, begin, end);

}

void merge(int *arr, const int begin, const int end) {
	int *tempArray = new int[end-begin+1]; // dynamically allocated memory to prevent waste of space
	
	int mid = (begin+end)/2;
	int k = 0, i = begin, j = mid+1; 
	
	while (i <= mid && j <= end)
		if (arr[i]  > arr[j])
			tempArray[k++] = arr[i++];
		else 
			tempArray[k++] = arr[j++];
	
	while (i <= mid ) tempArray[k++] = arr[i++];
	
	while (j <= end ) tempArray[k++] = arr[j++];
	
	for (i = begin; i <= end; ++i)
		arr[i] = tempArray[i-begin];
	
	delete[] tempArray; // deallocating the temporary array 
}
