#ifndef KGL
#define KGL

//#include"funkcja.hpp"

double funkcja(double x) {
	return sin(x);
}

#include <cmath>

double calka_metoda_gaussa_legendrea_2_wezly(double przedzialy, double pocz, double koniec) {
	double pole = 0;
	double next = pocz + (koniec - pocz) / przedzialy;
	double skok = (koniec - pocz) / przedzialy;
	double x1 = -0.577350;
	double x2 = 0.577350;


	for (int i = 0; i < przedzialy; ++i) {
		double t1 = ((pocz + next) / 2) + ((next- pocz) / 2) * x1;
		double t2 = ((pocz + next) / 2) + ((next - pocz) / 2) * x2;
		
		pole += ((next - pocz) / 2) * (funkcja(t1) * 1 + funkcja(t2) * 1);

		pocz = next;
		next += skok;
	}
	return pole;

}

double calka_metoda_gaussa_legendrea_4_wezly(double przedzialy, double pocz, double koniec) {
	double pole = 0;
	double next = pocz + (koniec - pocz) / przedzialy;
	double skok = (koniec - pocz) / przedzialy;

	double x1 = -0.86114;
	double x2 = -0.33998;
	double x3 = 0.33998;
	double x4 = 0.86114;

	double a1 = 0.34785;
	double a2 = 0.65214;
	double a3 = 0.65214;
	double a4 = 0.34785;

	for (int i = 0; i < przedzialy; ++i) {
		double t1 = ((pocz + next) / 2) + ((next - pocz) / 2) * x1;
		double t2 = ((pocz + next) / 2) + ((next - pocz) / 2) * x2;
		double t3 = ((pocz + next) / 2) + ((next - pocz) / 2) * x3;
		double t4 = ((pocz + next) / 2) + ((next - pocz) / 2) * x4;

		pole += ((next - pocz) / 2) * (a1*funkcja(t1) + a2 * funkcja(t2) + a3 * funkcja(t3) + a4 * funkcja(t4));

		pocz = next;
		next += skok;
	}
	return pole;

}


#endif // !KGL
