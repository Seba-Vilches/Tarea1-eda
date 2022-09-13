#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <list>
#include "sort/sort.hpp"
#include "sort/utils.hpp"

namespace sort{

	void selectionSort(float* A, int n){
		int smallest = 0;
		int i = 0;
		int j = 0;
		for (i = 0; i < n - 1; i++){
			smallest = i;
			for (j = i + 1; j < n; j++){
				if (A[j] < A[smallest]){
					smallest = j;
				}
			}
			swap(A,i,smallest);
		}
	}

	int split_qs(float* A, int i, int j){
		/***
		 * split for quicksort
		 * i,j are the endpoints
		 */
		int p = getRandomInt(i, j);
		while (i  < j) {
			while ( i < p && A[i] <= A[p]){
				i = i + 1;
			}
			while ( j > p && A[j] >= A[p]){
				j = j - 1;
			}
			swap(A, i, j);
			if (i == p){
				p = j;
			}
			else if (j == p){
				p = i;
			}
		}
		return p;
	}

	void quickSort(float* A, int i, int j){
		if (i < j){
			int k = split_qs(A, i, j);
			quickSort(A, i, k-1);
			quickSort(A, k + 1, j);
		}
	}

	void quickSort(float* A, int n){
		quickSort(A, 0, n - 1);
	}

	int  k_smallest(float* A, int i, int j, int k){
		int p = split_qs(A, i, j);
		int val = 0;
		if (k == p){
			val = A[p];
		}
		else if (k < p){
			val = k_smallest(A, i, p-1, k);
		}
		else{
			val = k_smallest(A, p+1, j, k);
		}
		return val;
	}

	int  k_smallest(float* A, int n, int k){
		return k_smallest(A, 0, n-1, k);
	}

	void mergeSort(float *A, int i, int j){
	int k = (i+j)/2;
	if(i<j){
		mergeSort(A, i, k);
		mergeSort(A, k + 1, j);
		merge(A, i, j, k);
		}
	}

	void mergeSort(float *A, int n){
		mergeSort(A, 0 , n - 1);
	}

	void insertionSort(float *A, int size){
		int key, j;
		for(int i = 1; i<size; i++) {
			key = A[i];
			j = i;
			while(j > 0 && A[j-1]>key) {
				A[j] = A[j-1];
				j--;
			}
			A[j] = key;
		}
	}

	void radixSort(float *arr, int n, int max) {
	int i, j, m, p = 1, index, temp, count = 0;
	std::list<int> pocket[10];
	for(i = 0; i< max; i++) {
		m = pow(10, i+1);
		p = pow(10, i);
		for(j = 0; j<n; j++) {
			temp = fmod(arr[j],m);
			index = temp/p;
			pocket[index].push_back(arr[j]);
			}
		count = 0;
		for(j = 0; j<10; j++) {
			while(!pocket[j].empty()) {
				arr[count] = *(pocket[j].begin());
				pocket[j].erase(pocket[j].begin());
				count++;
				}
			}
		}
	}

	void radixSort(float* A, int n){
		radixSort(A, 0, n - 1);
	}

}
