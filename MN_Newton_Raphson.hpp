#ifndef FUNKCJA
#define FUNKCJA
#include<cmath>

double funkcja1(double x1, double x2) {
	x1 = x1 * x1 * x1 + 2 * (x2 * x2);

	return x1;
}

double funkcja2(double x1,double x2) {
	x1 = 4 * x1 + sin(x2);


	return x1;
}

double pochodna1_x1(double x1,double x2) {
	
	return 3 * (x1 * x1);
}

double pochodna1_x2(double x1, double x2) {

	return 4 * x2;
}

double pochodna2_x1(double x1, double x2) {

	return 4;
}

double pochodna2_x2(double x1, double x2) {

	return cos(x2);
}

void NewtonRaphson(double x1,double x2, double dokladnosc) {
	double x_0[2];
	x_0[0] = x1;
	x_0[1] = x2;
	double macierz[2];
	double jakobian[2][2];
	double f_x[2];
	double dokladnosc;
	double wyznacznik = 0;
	int i = 1;
	while (fabs(funkcja1(x_0[0], x_0[1])) >= dokladnosc ||
		fabs(funkcja2(x_0[0], x_0[1])) >= dokladnosc) {
		//obliczenie jakobianu
		std::cout << "iteracja " << i << " " << std::endl;
		jakobian[1][1] = pochodna1_x1(x_0[0], x_0[1]);
		jakobian[1][0] = -pochodna1_x2(x_0[0], x_0[1]);
		jakobian[0][1] = -pochodna2_x1(x_0[0], x_0[1]);
		jakobian[0][0] = pochodna2_x2(x_0[0], x_0[1]);

		wyznacznik = jakobian[0][0] * jakobian[1][1] - jakobian[0][1] * jakobian[1][0];

		jakobian[0][0] *= 1 / wyznacznik;
		jakobian[0][1] *= 1 / wyznacznik;
		jakobian[1][0] *= 1 / wyznacznik;
		jakobian[1][1] *= 1 / wyznacznik;

		f_x[0] = funkcja1(x_0[0], x_0[1]);
		f_x[1] = funkcja2(x_0[0], x_0[1]);

		x_0[0] = x_0[0] - (f_x[0] * jakobian[0][0] + f_x[1] * jakobian[1][0]);
		x_0[1] = x_0[1] - (f_x[0] * jakobian[0][1] + f_x[1] * jakobian[1][1]);

		std::cout << "x1 = " << x_0[0] << std::endl;
		std::cout << "f1(x1,x2) = " << funkcja1(x_0[0], x_0[1]) << std::endl;
		std::cout << "x2 = " << x_0[1] << std::endl;
		std::cout << "f2(x1,x2) = " << funkcja2(x_0[0], x_0[1]) << std::endl << std::endl;

		++i;
	}
	std::cout << "x1 = " << x_0[0] << std::endl;
	std::cout << "x2 = " << x_0[1] << std::endl;

	std::cout << "f1(x1,x2) = " << funkcja1(x_0[0], x_0[1]) << std::endl;
	std::cout << "f2(x1,x2) = " << funkcja2(x_0[0], x_0[1]) << std::endl;
}


#endif // !FUNKCJA
