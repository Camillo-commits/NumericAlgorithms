#ifndef MC
#define MC

//#include"funkcja.hpp"

double funkcja(double x) {
	return sin(x);
}

#include<cstdlib>

double calkowanie_metoda_monte_carlo(int przedzialy, double pocz, double koniec, int ilosc_losowan) {
	double next = pocz + (koniec - pocz) / przedzialy;
	double skok = (koniec - pocz) / przedzialy;
	double bok = next - pocz;
	double pole = 0;

	//random seed
	srand(2);

	for (int i = 0; i < przedzialy; ++i) {
		double suma = 0;
		for (int j = 0; j < ilosc_losowan; ++j) {
			suma += fabs(funkcja(pocz + ((double)rand() / RAND_MAX ) * (next - pocz) ));
		}
		suma = suma / ilosc_losowan;
		pole += bok * suma;

		pocz = next;
		next += skok;
	}
	return pole;
}

#endif