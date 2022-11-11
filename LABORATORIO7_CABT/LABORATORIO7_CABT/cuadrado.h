#pragma once
#include "poligono.h"

class cuadrado : poligono {
public:
	double Calcular_PerimetroC(double l);
	double Calcular_AreaC(double l);
};

double cuadrado::Calcular_AreaC(double l) {
	double area_cuadrado = lado * lado;
	return area_cuadrado;
}

double cuadrado::Calcular_PerimetroC(double l) {
	double perimetro_cuadrado = 4 * (lado);
	return perimetro_cuadrado;
}

