#pragma once
#include "poligono.h"

class triangulo:poligono
{
public:
	double Calcular_PerimetroT(double l);
	double Calcular_AreaT(double b, double h);
};

double triangulo::Calcular_AreaT(double b, double h) {
	double area_triangulo = (base * altura) / 2;
	return area_triangulo;
}

double triangulo::Calcular_PerimetroT(double l) {
	double perimetro_triangulo = lado * 3;
	return perimetro_triangulo;
}

