#pragma once
#include "poligono.h"

class rectangulo : poligono {
public:
	double Calcular_AreaR(double b, double h);
	double Calcular_PerimetroR(double b, double h);
};

double rectangulo::Calcular_AreaR(double b, double h) {
	double area_rectangulo = base * altura;
	return area_rectangulo;
}

double rectangulo::Calcular_PerimetroR(double b, double h) {
	double suma_bases = 2 * (base);
	double suma_alturas = 2 * (altura);

	double perimetro_rectangulo = suma_bases + suma_alturas;

	return perimetro_rectangulo;
}