#include <iostream>
#include <cmath>
#include "IkiBoyuttaHareket.h"

#define PI 3.14159265



void IkiBoyuttaCarpisma::run() {

	int choice;
	double v1, m1, v2, m2, alfa1, alfa2;
	double radyalalfa1, radyalalfa2;
	double v1x, v1y, v2x, v2y;


	std::cout << "---  Iki Boyutta Carpisma  ---\n\n";

	std::cout << "1-Esnek Carpisma\n";
	std::cout << "2-Esnek olmayan Carpisma\n";
	std::cout << "Carpisma turunu seciniz -> ";
	std::cin >> choice;

	std::cout << "Birinci cismin hizi    -> ";
	std::cin >> v1;
	std::cout << "Birinci cismin kutlesi -> ";
	std::cin >> m1;
	std::cout << "Birinci cismin x ekseni ile yaptigi aci  -> ";
	std::cin >> alfa1;
	std::cout << "\n";
	std::cout << "Ikinci cismin hizi     -> ";
	std::cin >> v2;
	std::cout << "Ikinci cismin kutlesi  -> ";
	std::cin >> m2;
	std::cout << "Ikinci cismin x ekseni ile yaptigi aci  -> ";
	std::cin >> alfa2;
	std::cout << "\n";


	if (((choice == 1) || (choice == 2)) != 1) {
		std::cout << "Hatali giris yaptiniz \n";
		return;
	}

	radyalalfa1 = alfa1 * (PI / 180);
	radyalalfa2 = alfa2 * (PI / 180);

	v1x = v1 * cos(radyalalfa1);
	v1y = v1 * sin(radyalalfa1);
	v2x = v2 * cos(radyalalfa2);
	v2y = v2 * sin(radyalalfa2);

	switch (choice) {
	case 1:
		std::cout << "Carpisma Sonrasi  \n";
		std::cout << "Birinci Cismin Hizi  ->   Vx : " << esnekCarpismaV1(v1x, m1, v2x, m2) << "   Vy : " << esnekCarpismaV1(v1y, m1, v2y, m2) << "\n";
		std::cout << "Ikinci Cismin Hizi   ->   Vx : " << esnekCarpismaV2(v1x, m1, v2x, m2) << "   Vy : " << esnekCarpismaV2(v1y, m1, v2y, m2) << "\n\n";
		break;
	case 2:
		std::cout << "Capisma sonrasi cismin kutlesi -> " << m1 + m2 << "\n";
		std::cout << "Carpisma sonrasi cismin hizi   ->     Vx :  " << esnekOlmayanCarpisma(v1x, m1, v2x, m2) << "   Vy : " << esnekOlmayanCarpisma(v1y, m1, v2y, m2) << "\n\n";
		break;
	}

}


double IkiBoyuttaCarpisma::esnekOlmayanCarpisma(double v1, double m1, double v2, double m2) {
	return (((m1 * v1) + (m2 * v2)) / (m1 + m2));
}

double IkiBoyuttaCarpisma::esnekCarpismaV1(double v1, double m1, double v2, double m2) {
	return (((m1 - m2) * v1 + 2 * m2 * v2) / (m1 + m2));
}

double IkiBoyuttaCarpisma::esnekCarpismaV2(double v1, double m1, double v2, double m2) {
	return (((m2 - m1) * v2 + 2 * m1 * v1) / (m1 + m2));
}