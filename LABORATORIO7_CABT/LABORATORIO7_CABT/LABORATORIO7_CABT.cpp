
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
		numeros[i] = rand() % 1000;
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
			//INSTANCIAMOS LA CLASE DE ORDENAMIENTO
			ordenamiento s;

			n = sizeof(numeros) / sizeof(numeros[0]);
			
			
			for (i = 0; i < sizeof(numeros); i++) {
				numeros[i];
			}
			

			//ordenamiento ordenar;
			s.quickSort(numeros, 0, n - 1);
			cout << "------ A R R E G L O  O R D E N A D O ------" << "\r\n";

			for (i = 0; i < sizeof(numeros); i++) {
				cout << numeros[i] << endl;
			}
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
	



