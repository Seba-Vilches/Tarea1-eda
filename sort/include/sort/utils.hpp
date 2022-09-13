#ifndef SORT_UTILS_HPP
#define SORT_UTILS_HPP

namespace sort{
	float* createArray(int n);
	float* createRandomArray(int n);
	float* createRandomIntArray(int n, int minVal = 0, int maxVal = 100);
	void deleteArray(float* A);
	void deleteArray2(int* B);
	void printArray(float* A, int n);
	void printArray2(int* B, int n);
	void setAll(float* A, int n, float value);
	void swap(float* A, int i, int j);
	int getRandomInt(int min, int max);
	int* linspace(int max, int n_parts);
	int getMax(int arr[], int n);
	void countSort(int arr[], int n, int exp);
	void merge(float* A, int i, int j, int k);
}

#endif
