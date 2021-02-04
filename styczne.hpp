#ifndef STYCZNE
#define STYCZNE
//#include "funkcja.hpp"

double funkcja(double X) {
	return cos(X);

}

double pochodna(double X) {
	return -sin(X);
}

double styczne(double start, double koniec, double dokladnosc) {
	double x;
	double f_x;
	x = start;
	//czy jest to potrzebne?
	if (funkcja(start) * funkcja(koniec) > 0) {
		std::cout << "brak miejsca zerowego lub parzysta liczba miejsc zerowych" << std::endl;
		return -1;
	}

	int iter = 0;
	while (fabs(funkcja(x)) > dokladnosc) {
		std::cout << "iteracja " << iter << std::endl;
		x = x - (funkcja(x) / pochodna(x));
		std::cout << "x = " << x << std::endl;
		++iter;
	}
	return x;
}

#endif // !STYCZNE
