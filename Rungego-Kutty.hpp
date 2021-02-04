#ifndef RK
#define RK

//#include "funkcja.hpp"
#include <iostream>

double pochodna_funkcji(double x, double y) {
	return x * x + y;
}

double metoda_RK2(double x_wynikowy, double liczba_krokow, double x0, double y0) {
	double skok = (x_wynikowy - x0) / liczba_krokow;
	double x1;
	
	
	double k1;
	double k2;
	double srednia;
	
	std::cout << "Metoda RK2" << std::endl;
	std::cout << "x0 = " << x0 << std::endl;
	std::cout << "y0 = " << y0 << std::endl;

	for (int i = 0; i < liczba_krokow; ++i) {
		x1 = x0 + skok;
		k1 = pochodna_funkcji(x0, y0);
		k2 = pochodna_funkcji(x0 + skok, y0 + skok * k1);
		srednia = (k1 + k2) / 2;

		y0 = y0 + skok * srednia;
		

		std::cout << "iteracja: " << i << std::endl;
		std::cout << "x" << i + 1 << " = " << x1 << std::endl;
		std::cout << "y" << i + 1 << " = " << y0 << std::endl;
		
		x0 = x1;
	}
	std::cout << "wynik metoda RK2 y(" << x_wynikowy << ") = " << y0 << std::endl;
	return y0;
}

double metoda_RK4(double x_wynikowy, double liczba_krokow, double x0, double y0) {

	double skok = (x_wynikowy - x0) / liczba_krokow;

	double x1;
	
	double k1;
	double k2;
	double k3;
	double k4;

	double srednia;

	std::cout << "Metoda RK4" << std::endl;
	std::cout << "x0 = " << x0 << std::endl;
	std::cout << "y0 = " << y0 << std::endl;

	for (int i = 0; i < liczba_krokow; ++i) {
		x1 = x0 + skok;

		k1 = pochodna_funkcji(x0, y0);
		k2 = pochodna_funkcji(x0 + (skok / 2),y0 + (skok * k1 / 2));
		k3 = pochodna_funkcji(x0 + (skok / 2), y0 + (skok * k2 / 2));
		k4 = pochodna_funkcji(x0 + skok, y0 + skok * k3);
		srednia = (k1 + 2 * k2 + 2 * k3 + k4) / 6;

		y0 = y0 + skok * srednia;

		std::cout << "iteracja: " << i << std::endl;
		std::cout << "x" << i + 1 << " = " << x1 << std::endl;
		std::cout << "y" << i + 1 << " = " << y0 << std::endl;

		x0 = x1;
	}
	std::cout << "wynik metoda RK4 y(" << x_wynikowy << ") = " << y0 << std::endl;
	return y0;
}

#endif // !RK

