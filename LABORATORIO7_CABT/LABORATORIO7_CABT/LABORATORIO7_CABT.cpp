
#include <iostream>
using namespace std;
#include  "ordenamiento.h"

int main()
{
	int cantidad_numeros = 0, i, option, n;

	//CICLO DO-WHILE PARA SOLICITAR EL TAMAÑO DE NUESTRO VECTOR
	do
	{
		cout << "Ingrese la cantidad de posiciones a generar" << "\r\n";
		cin >> cantidad_numeros;
		if (cantidad_numeros <= 0) cout << "Ingrese un valor mayor a 0" << "\r\n";
	} while (cantidad_numeros <= 0);

	//CREACIÓN DE UN ARREGLO DINÁMICO
	int* numeros = new int[cantidad_numeros];

	//LLENAR EL ARREGLO
	for (i = 0; i < cantidad_numeros; i++) {
		numeros[i] = rand() % 10;
	}
	cout << "A R R E G L O  C O N  N U M E R O S  A L E A T O R I O S" << "\r\n";
	//IMPRIMIR EL ARREGLO
	for (i = 0; i < cantidad_numeros; i++) {
		cout << "POSICION [ " << i << " ]:" << numeros[i] << " " << "\r\n";
	}

	//CICLO DO-WHILE PARA NUESTRO MENÚ DE OPCIONES
	do
	{
		cout << "------ M E N U  D E  O P C I O N E S ------" << "\r\n";
		cout << "1. INGRESAR NUMERO A BUSCAR" << "\r\n";
		cout << "2. SALIR DEL PROGRAMA" << "\r\n";
		cin >> option;

		//ESTRUCTURA SWITCH & CASE PARA LA EVALUACIÓN DE LAS DISTINTAS OPCIONES DEL MENÚ
		switch (option)
		{
		case 1:
			n = sizeof(numeros[0]) / sizeof(numeros[0]);
			//ordenamiento ordenar;
			quickSort(numeros, 0, n - 1);
			cout << "------ A R R E G L O  O R D E N A D O ------" << "\r\n";
			printArray(numeros, n);
			break;
		case 2:
			cout << "HASTA PRONTO!" << "\r\n";
			system("cls");
			exit(0);
			break;
		default:
			cout << "NINGUNA OPCION SELECCIONADA Y/O VALIDA" << "\r\n";
			system("cls");
			exit(0);
			break;
		}
	} while (option != 2);
};
	void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

	  /* This function takes last element as pivot, places
  the pivot element at its correct position in sorted
  array, and places all smaller (smaller than pivot)
  to left of pivot and all greater elements to right
  of pivot */
 int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot 
	int i = (low - 1); // Index of smaller element and indicates
	// the right position of pivot found so far

	for (int j = low; j <= high - 1; j++) {
		// If current element is smaller than the pivot
		if (arr[j] < pivot) {
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

	  /* The main function that implements QuickSort
  arr[] --> Array to be sorted,
  low --> Starting index,
  high --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
	  /* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}



