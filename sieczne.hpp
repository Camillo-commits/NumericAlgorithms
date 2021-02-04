#ifndef SIECZNE
#define SIECZNE
//#include "funkcja.hpp"

double funkcja(double X) {
	return cos(X);

}

double pochodna(double X) {
	return -sin(X);
}

double sieczne(double start, double koniec, double dokladnosc) {
	double x1 = start;
	double x2;
	double wynik;

	std::cout << "podaj drugi punkt startowy " << std::endl;
	std::cin >> x2;

	if (funkcja(start) * funkcja(koniec) > 0) {
		std::cout << "brak miejsca zerowego lub parzysta liczba miejsc zerowych" << std::endl;
		return -1;
	}

	int iter = 0;
	while (fabs(funkcja(x1)) > dokladnosc) {
		std::cout << "iteracja " << iter << std::endl;
		wynik = x1 - (((x1 - x2) / (funkcja(x1) - funkcja(x2))) * funkcja(x1));
		std::cout << "x =" << wynik << std::endl;
		x2 = x1;
		x1 = wynik;
		++iter;
	}
	return x1;
}

#endif // !SIECZNE
