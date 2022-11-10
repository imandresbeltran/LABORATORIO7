#pragma once
#include <iostream>
using namespace std;

class binarysearch
{
public: int binarySearch(int arr[], int x, int low, int high) {
	if (high >= low) {
		int mid = low + (high - low) / 2;

		//If found at mid, then return it

		if (arr[mid] == x)
			return mid;
		
		//Search the left half

		if (arr[mid] > x)
			return binarySearch(arr, x, low, mid - 1);

		//Search the right half
		return binarySearch(arr, x, mid + 1, high);
	}

	return -1;
}

};

