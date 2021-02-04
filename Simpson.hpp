#ifndef SIM
#define SIM

//#include"funkcja.hpp"

double funkcja(double x) {
	return sin(x);
}

double calka_metoda_simpsona(int przedzialy, double pocz, double koniec) {
	double next = pocz + (koniec - pocz) / przedzialy;
	double skok = (koniec - pocz) / przedzialy;
	double bok = next - pocz;
	double pole = 0;

	for (int i = 0; i < przedzialy; ++i) {

		pole += (funkcja(pocz) + 4 * funkcja((pocz + next) / 2) + funkcja(next)) * ((next - pocz) / 6);

		pocz = next;
		next += skok;
	}
	return pole;
}

#endif // !SIM
