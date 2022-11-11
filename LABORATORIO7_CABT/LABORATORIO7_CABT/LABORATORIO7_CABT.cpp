
#include <iostream>
#include <windows.h>
#include <TCHAR.h>
using namespace std;
#include  "ordenamiento.h"
#include "linearsearch.h"
#include "validaciones.h"
#include "binarysearch.h"
#include "hashTable.h"
#include "cuadrado.h"
#include "rectangulo.h"
#include "triangulo.h"

int main()
{
	int cantidad_numeros = 0, i, option, n, buscar = 0, searchmethod, x, result, ejercicio, figuras;
	double lado, base, altura;
	hashTable HT;

exercises:
	do {
		cout << "P R O G R A M A  O R I E N T A D O  A  O B J E T O S" << "\r\n";
		cout << "SELECCIONA QUE PROGRAMA DESEAS EJECUTAR" << "\r\n";
		cout << "1. METODOS DE BUSQUEDA Y ORDENAMIENTO" << "\r\n";
		cout << "2. CALCULAR AREAS Y PERIMETROS" << "\r\n";
		cout << "3. SALIR" << "\r\n";
		cin >> ejercicio;

		switch (ejercicio)
		{
		case 1: 
			goto numbers;
			break;
		case 2:
			cout << "SELECCIONE UNA FIGURA" << "\r\n";
			cout << "1. CUADRADO" << "\r\n";
			cout << "2. RECTANGULO" << "\r\n";
			cout << "3. TRIANGULO" << "\r\n";
			cout << "4. SALIR" << "\r\n";
			cin >> figuras;

			switch (figuras)
			{
			case 1: 
				cuadrado cuadrado;
				validaciones validar;
				cout << "INGRESE EL LADO: " << "\r\n";
				cin >> lado;
				if (validar.validarnumero(lado) == true) {
					double cuadrado_area = cuadrado.Calcular_AreaC(lado);
					double cuadrado_perimetro = cuadrado.Calcular_PerimetroC(lado);
					cout << "EL AREA DEL CUADRADO ES: " << cuadrado_area << "\r\n";
					cout << "EL PERIMETRO DEL CUADRADO ES: " << cuadrado_perimetro << "\r\n";
				}
				else {
					cout << "ERROR" << "\r\n";
				}
				break;
			case 2:
				rectangulo rectangulo;
				validaciones validar;

				cout << "INGRESE LA BASE: " << "\r\n";
				cin >> base;

				cout << "INGRESE LA ALTURA: " << "\r\n";
				cin >> altura;

				if (validar.validarnumero(base) == true && validar.validarnumero(altura) == true) {
					double area_rectangulo = rectangulo.Calcular_AreaR(base, altura);
					double perimetro_rectangulo = rectangulo.Calcular_PerimetroR(base, altura);
					cout << "EL AREA DEL RECTANGULO ES: " << area_rectangulo << "\r\n";
					cout << "EL PERIMETRO DEL RECTANGULO ES: " << perimetro_rectangulo << "\r\n";
				}
				else {
					cout << "ERROR" << "\r\n";
				}
				break;
			case 3:
				triangulo triangulo;
				validaciones validar;

				cout << "INGRESE LA BASE: " << "\r\n";
				cin >> base;

				cout << "INGRESE LA ALTURA: " << "\r\n";
				cin >> altura;

				cout << "INGRESE EL LADO: " << "\r\n";
				cin >> lado;

				if (validar.validarnumero(base) == true && validar.validarnumero(altura) == true && validar.validarnumero(lado)) {
					double area_triangulo = triangulo.Calcular_AreaT(base, altura);
					double perimetro_triangulo = triangulo.Calcular_PerimetroT(lado);

					cout << "EL AREA DEL TRIANGULO ES: " << area_triangulo << "\r\n";
					cout << "EL PERIMETRO DEL TRIANGULO ES: " << perimetro_triangulo << "\r\n";
				}
				break;
			default:
				cout << "INGRESA UNA OPCION VALIDA" << "\r\n";
				break;
			}

			break;
		case 3:
			exit(0);
			break;
		default:
			cout << "NINGUNA OPCIÓN SELECCIONADA. VUELVE A INTENTARLO" << "\r\n";
			break;
		}
	} while (ejercicio != 3);

	numbers:
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
	options1:
	do
	{
		cout << "------ M E N U  D E  O P C I O N E S ------" << "\r\n";
		cout << "1. ORDENAR ARREGLO" << "\r\n";
		cout << "2. SALIR DEL PROGRAMA" << "\r\n";
		cin >> option;

		//ESTRUCTURA SWITCH & CASE PARA LA EVALUACIÓN DE LAS DISTINTAS OPCIONES DEL MENÚ
		switch (option)
		{
		case 1:
			//INSTANCIAMOS LA CLASE DE ORDENAMIENTO
			ordenamiento s;
			
			//ordenamiento ordenar;
			s.quickSort(numeros, 0, cantidad_numeros - 1);
			cout << "------ A R R E G L O  O R D E N A D O ------" << "\r\n";

			for (i = 0; i < cantidad_numeros; i++) {
				cout << "POSICION [ " << i << " ] = " << numeros[i] << endl;
			}

			cout << "AHORA QUE EL ARREGLO SE ENCUENTRA ORGANIZADO, SELECCIONA UN MÉTODO DE BÚSQUEDA" << "\r\n";
			
			searches:
			do {
				cout << "------ M E T O D O S  D E  B U S Q U E D A ------" << "\r\n";
				cout << "1. METODO SECUENCIAL" << "\r\n";
				cout << "2. METODO BINARIO" << "\r\n";
				cout << "3. METODO HASHING" << "\r\n";
				cout << "4. REGRESAR" << "\r\n";
				cin >> searchmethod;

				switch (searchmethod) {
				case 1:
					//INSTANCIAMOS LA CLASE
					linearsearch secuencial;

					//RECOLECTAMOS EL VALOR A BUSCAR
					
					cout << "INGRESA EL NUMERO QUE DESEAS BUSCAR: " << "\r\n";
					cin >> x;

					//MANDAMOS A LLAMAR LA FUNCIÓN
					result = secuencial.search(numeros, cantidad_numeros, x);
					(result == -1)
						? cout << "EL NUMERO NO ESTA PRESENTE EN EL ARREGLO"
						: cout << "EL ELEMENTO ESTA EN EL INDICE: " << result;
					break;
				case 2:
					binarysearch busquedabinaria;

					cout << "INGRESA EL NUMERO QUE DESEAS BUSCAR :" << "\r\n";
					cin >> x;

					//LLAMAMOS LA FUNCIÓN
					result = busquedabinaria.binarySearch(numeros, x, 0, cantidad_numeros - 1);
					(result == -1)
						? cout << "EL NUMERO NO ESTA PRESENTE EN EL ARREGLO"
						: cout << "EL NUMERO SE ENCUENTRA EN LA POSICION: " << result;
					break;
				case 3:
					

					if (HT.isEmpty()) {
						cout << "Correct answer. Good job!" << "\r\n";
					}
					else {
						cout << "Oh no. We need to check out code!" << "\r\n";
					}

					for (i = 0; i < cantidad_numeros; i++) {
						HT.insertItem(rand() % 100, numeros[i]);
					}

					HT.printTable();
					break;
				case 4:
					goto options1;
					break;
				default:
					cout << "NINGUNA OPCION VALIDA SELECCIONADA" << "\r\n";
					goto searches;
					break;
				}
			} while (searchmethod != 4);
			
			validaciones validar;

			if (validar.validarnumero(buscar) == true) cout << "NÚMERO A BUSCAR VÁLIDO" << "\r\n";
			else cout << "INGRESE UN VALOR MAYOR A 0" << "\r\n";
			break;
		case 2:
			cout << "HASTA PRONTO!" << "\r\n";
			system("cls");
			goto numbers;
			break;
		default:
			cout << "NINGUNA OPCION SELECCIONADA Y/O VALIDA" << "\r\n";
			system("cls");
			exit(0);
			break;
		}
	} while (option != 2);
};

	



