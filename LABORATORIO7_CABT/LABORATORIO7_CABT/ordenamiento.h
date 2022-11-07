#pragma once
#include <iostream>
using namespace std;

//IMPLEMENTACIÓN DEL MÉTODO DE ORDENAMIENTO (QUICK SORT)

class ordenamiento
{
public: void swap(int arr[], int pos1, int pos2) {
		int temp;
		temp = arr[pos1];
		arr[pos1] = arr[pos2];
		arr[pos2] = temp;
	}

public: int partition(int arr[], int low, int high, int pivot) {
	int i = low;
	int j = low;

	while (i <= high) {
		if (arr[i] > pivot) {
			i++;
		}
		else {
			swap(arr, i, j);
			i++;
			j++;
		}
	}

	return j - 1;
}

public: void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pivot = arr[high];
		int pos = partition(arr, low, high, pivot);

		quickSort(arr, low, pos - 1);
		quickSort(arr, pos + 1, high);
	}
}
};


