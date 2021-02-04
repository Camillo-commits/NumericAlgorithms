#ifndef BISEKCJA
#define BISEKCJA
#include <iostream>
#include <cmath>


double funkcja(double x) {
	//funkcja nr 1
	double wynik = 0;
	wynik += 2 * pow(x, 2);
	wynik += 6 * x;
	return wynik;

	//funkcja nr 2
	//return log(x);
	
	/*funkcja nr 3
	return x * sin(x) * cos(x);
	*/
}

double bisekcja(double zakres_L, double zakres_P, double dokladnosc) {
	double lewa;
	double prawa;
	double srodek;

	lewa = funkcja(zakres_L);
	prawa = funkcja(zakres_P);
	if (lewa * prawa < 0) {
		srodek = funkcja((zakres_P + zakres_L) / 2);
		//wypisanie wyniku poszczegolnej iteracji
		//std::cout << (zakres_P + zakres_L) / 2 << std::endl;
		//wypisanie zakresu
		std::cout << zakres_L << ";" << zakres_P << std::endl;

		//warunek skonczenia funkcji
		if (fabs(srodek) < dokladnosc){
			return (zakres_P + zakres_L) / 2;
		}

		if (lewa > 0 && srodek > 0) {
			srodek = bisekcja((zakres_P + zakres_L) / 2, zakres_P, dokladnosc);
		}
		else if (lewa > 0 && srodek < 0) {
			srodek = bisekcja(zakres_L, (zakres_P + zakres_L) / 2,dokladnosc);
		}
		else if (lewa < 0 && srodek > 0) {
			srodek = bisekcja(zakres_L, (zakres_P + zakres_L) / 2, dokladnosc);
		}
		else if (lewa < 0 && srodek < 0) {
			srodek = bisekcja((zakres_P + zakres_L) / 2, zakres_P, dokladnosc);
		}
		return srodek;
	}
	else {
		std::cout << "miejsce zerowe w tym przedziale nie istnieje" << std::endl;
	}
}

#endif // !BISEKCJA
