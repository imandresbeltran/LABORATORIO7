#pragma once
#include <iostream>
using namespace std;
class validaciones
{
public: bool validarnumero(int numero) {
	bool condicion = false;

	if (numero > 0) condicion = true;
	else condicion = false;
	return condicion;
}
};

