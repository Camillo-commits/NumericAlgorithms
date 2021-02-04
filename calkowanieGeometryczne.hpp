#ifndef CALKA 
#define CALKA
#include<cmath>
#include<iostream>

double funkcja(double x) {
	return 7 / x;
}

double metoda_kwadratow(double a, double b, unsigned int przedzialy) {
	double next = a + (b - a) / przedzialy ;
	double skok = (b - a) / przedzialy;
	double bok = next - a;
	double wysokosc;
	double pole = 0;

	for (int i = 0; i < przedzialy; ++i) {
		wysokosc = fabs(funkcja(a));

		pole += bok * wysokosc;
		/*
		std::cout << "iteracja: " << i << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "next = " << next << std::endl;
		std::cout << "pole = " << pole << std::endl << std::endl;
		*/
		a = next;
		next += skok;
	}
	return pole;
}

double metoda_trapezow(double a, double b, unsigned int przedzialy) {
	double next = a + (b - a) / przedzialy;
	double skok = (b - a) / przedzialy;
	double bok = next - a;
	double wysokosc_a,wysokosc_b;
	double pole = 0;

	for (int i = 0; i < przedzialy; ++i) {
		wysokosc_a = funkcja(a);
		wysokosc_b = funkcja(next);

		pole += fabs((wysokosc_a + wysokosc_b) * bok / 2);
		/*
		std::cout << "iteracja: " << i << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "next = " << next << std::endl;
		std::cout << "pole = " << pole << std::endl << std::endl;
		*/
		a = next;
		next += skok;

	}
	return pole;
}


#endif // !CALKA
