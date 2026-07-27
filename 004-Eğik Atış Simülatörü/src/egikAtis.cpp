#include <iostream> 
#include <math.h>
#include "egikAtis.h"

#define PI 3.14159265
#define g 9.80665


void EgikAtis::run() {

	double aci, hiz;


	do
	{
		std::cout << "\n--- Egik Atis Simülatoru ---\n\n";
		std::cout << "Hiz Degerini Giriniz(m/s)  :";
		std::cin >> hiz;
		std::cout << "Aci Degerini Giriniz       :";
		std::cin >> aci;

		std::cout << "  Menzil        :" << menzil(hiz, aci) << "\n";
		std::cout << "  Max Yukseklik :" << maxYukseklik(hiz, aci) << "\n";
		std::cout << "  Ucus Suresi   :" << ucusSuresi(hiz, aci) << "\n\n";
		std::cout << "  cikmak icin hiz degerini 0 girin  \n";
		
	} while (hiz != 0);

}


double EgikAtis::menzil(double hiz, double aci) {
	double radyanAci = aci * (PI / 180);

	return((2 * hiz * hiz * sin(radyanAci) * cos(radyanAci) / g));

}

double EgikAtis::maxYukseklik(double hiz, double aci) {
	double radyanAci = aci * (PI / 180);
	return ((hiz * hiz * sin(radyanAci) * sin(radyanAci) / (2 * g)));

}

double EgikAtis::ucusSuresi(double hiz, double aci) {
	double radyanAci = aci * (PI / 180);
	return ((2 * hiz * sin(radyanAci)) / g);
}

