#pragma once
#include <iostream>
using namespace std;

class linearsearch
{

	//M�TODO PARA REALIZAR LA B�SQUEDA LINEAL
public: int search(int arr[], int N, int x) {
	for (int i = 0; i < N; i++)
		if (arr[i] == x)
			return i;
	return -1;
}
};

