#ifndef EULER
#define EULER
#include <iostream>

//#include"funkcja.hpp"

double pochodna_funkcji(double x, double y) {
	return x * x + y;
}

double metoda_eulera(double x_wynikowy,double liczba_krokow, double x0,double y0){
	double x1;
	double y1;

	std::cout << "metoda Eulera" << std::endl;
	std::cout << "x0 = " << x0 << std::endl;
	std::cout << "y0 = " << y0 << std::endl;

	double skok = (x_wynikowy - x0) / liczba_krokow;
	for (int i = 0; i < liczba_krokow; ++i) {
		x1 = x0 + skok;
		y1 = y0 + skok * pochodna_funkcji(x0, y0);

		std::cout << "iteracja: " << i << std::endl;
		std::cout << "x" << i+1 << " = " << x1 << std::endl;
		std::cout << "y" << i+1 << " = " << y1 << std::endl;

		x0 = x1;
		y0 = y1;
	}
	std::cout << "wynik metoda eulera y(" << x_wynikowy << ") = " << y1 << std::endl;
	return y1;
}

#endif 