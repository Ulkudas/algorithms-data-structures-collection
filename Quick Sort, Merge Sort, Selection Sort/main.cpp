/*-----------------------------------
*	Author: Mehmet Enes Keles
*
*	Description: This code compares execution times of selection sort, merge sort & quicksort algorithms
*                on arrays with different size and order
*
* 	P.S: Don't forget to set stack size to unlimited by typing 'ulimit -s unlimited' before you run the code 
*-------------------------------------*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "sorting.h"

using namespace std;

// prints out the execution time of the given sorting function
void printTime(int *arr, const int n, void (*sortingFunc)(int*, int), string funcName) { 
	int *temp = new int[n+5]; // copying the original array to prevent changes 

	for (int i = 0; i < n; ++i) 
		temp[i] = arr[i];

	// calculating the execution time 
	clock_t startTime = clock();
	sortingFunc(temp, n); 
	double duration = 1000*double(clock() - startTime)/CLOCKS_PER_SEC;
	// ------------------------
	
	cout<<"Execution of "<<funcName<<" for "<<n<<" elements took "<<duration<<" milliseconds"<<endl;	 

	delete[] temp;
}

int main(int argc, char** argv) {
	srand(time(NULL));
	
	int R25K[25000], R100K[100000], R500K[500000];
	int D25K[25000], D100K[100000], D500K[500000];
	int A25K[25000], A100K[100000], A500K[500000];
	
	for (int i = 0; i < 25000; ++i)
		D25K[i] = R25K[i] = rand();
	
	for (int i = 0; i < 100000; ++i)
		D100K[i] = R100K[i] = rand();

	for (int i = 0; i < 500000; ++i)
		D500K[i] = R500K[i] = rand();
	
	// creating arrays in descending order by using MergeSort
	mergeSort(D25K, 25000);     // takes about 3-4 milliseconds
	mergeSort(D100K, 100000);  	// takes about 13-14 milliseconds
	mergeSort(D500K, 500000);   // takes about 75 milliseconds
	
	// creating arrays in ascending order by reversing arrays that are in descending order
	for (int i = 0 ; i < 25000; ++i)
		A25K[25000-i-1] = D25K[i]; 

	for (int i = 0 ; i < 100000; ++i)
		A100K[100000-i-1] = D100K[i];
	
	for (int i = 0 ; i < 500000; ++i)
		A500K[500000-i-1] = D500K[i];	
	
	// testing algorithms on randomized arrays
	printTime(R25K, 25000, selectionSort, "Selection Sort"); 
	printTime(R25K, 25000, mergeSort, "MergeSort"); 
	printTime(R25K, 25000, quickSort, "QuickSort"); 
	cout<<endl;
	
	printTime(R100K, 100000, selectionSort, "Selection Sort");
	printTime(R100K, 100000, mergeSort, "Merge Sort");
	printTime(R100K, 100000, quickSort, "Quick Sort");
	cout<<endl;
	printTime(R500K, 500000, selectionSort, "Selection Sort") ;
	printTime(R500K, 500000, mergeSort, "Merge Sort") ;
	printTime(R500K, 500000, quickSort, "Quick Sort") ;
	cout<<endl; 
	cout<<endl;

	// testing algorithms on arrays in descending order
	printTime(D25K, 25000, selectionSort, "Selection Sort"); 
	printTime(D25K, 25000, mergeSort, "MergeSort"); 
	printTime(D25K, 25000, quickSort, "QuickSort"); 
	cout<<endl;
	printTime(D100K, 100000, selectionSort, "Selection Sort") ;
	printTime(D100K, 100000, mergeSort, "Merge Sort");
	printTime(D100K, 100000, quickSort, "Quick Sort");
	cout<<endl;
	printTime(D500K, 500000, selectionSort, "Selection Sort");
	printTime(D500K, 500000, mergeSort, "Merge Sort");
	printTime(D500K, 500000, quickSort, "Quick Sort");
	cout<<endl;
	cout<<endl;

	// testing algorithms on arrays in ascending order
	printTime(A25K, 25000, selectionSort, "Selection Sort"); 
	printTime(A25K, 25000, mergeSort, "MergeSort"); 
	printTime(A25K, 25000, quickSort, "QuickSort"); 
	cout<<endl;
	printTime(A100K, 100000, selectionSort, "Selection Sort");
	printTime(A100K, 100000, mergeSort, "Merge Sort");
	printTime(A100K, 100000, quickSort, "Quick Sort");
	cout<<endl;
	printTime(A500K, 500000, selectionSort, "Selection Sort");
	printTime(A500K, 500000, mergeSort, "Merge Sort");
	printTime(A500K, 500000, quickSort, "Quick Sort");
	
	return 0;
}
