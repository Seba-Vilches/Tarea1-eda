#ifndef SORT_SORT_HPP
#define SORT_SORT_HPP

namespace sort{
	void selectionSort(float* A, int n);
	
	void quickSort(float* A, int i, int j);
	void quickSort(float* A, int n);
	
	void mergeSort(float *A, int i, int j);
	void mergeSort(float *A, int n);

	void insertionSort(float* A, int n);

	void radixSort(float* A, int n, int max);
	void radixSort(float* A, int n);

	int  k_smallest(float* A, int i, int j, int k);
	int  k_smallest(float* A, int n, int k);
	int split_qs(float* A, int i, int j);
}

#endif