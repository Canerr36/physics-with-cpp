#include <iostream>
#include "BirBoyuttaCarpisma.h"



void BirBoyuttaCarpisma::run() {

	int choice;
	double v1, m1, v2, m2;

	std::cout << "---  Bir Boyutta Carpisma  ---\n\n";

	std::cout << "1-Esnek Carpisma\n";
	std::cout << "2-Esnek olmayan Carpisma\n";
	std::cout << "Carpisma turunu seciniz -> ";
	std::cin >> choice;

	std::cout << "Birinci cismin hizi    -> ";
	std::cin >> v1;
	std::cout << "Birinci cismin kutlesi -> ";
	std::cin >> m1;
	std::cout << "\n";
	std::cout << "Ikinci cismin hizi     -> ";
	std::cin >> v2;
	std::cout << "Ikinci cismin kutlesi  -> ";
	std::cin >> m2;
	std::cout << "\n";


	if (((choice == 1) || (choice == 2)) != 1) {
		std::cout << "Hatali giris yaptiniz \n";
		return;
	}

	switch (choice) {
	case 1:
		std::cout << "Carpisma Sonrasi  \n";
		std::cout << "Birinci Cismin Hizi  ->" << esnekCarpismaV1(v1, m1, v2, m2) << "\n";
		std::cout << "Ikinci Cismin Hizi   ->" << esnekCarpismaV2(v1, m1, v2, m2) << "\n\n";
		break;
	case 2:
		std::cout << "Capisma sonrasi cismin kutlesi -> " << m1 + m2 << "\n";
		std::cout << "Carpisma sonrasi cismin hizi   -> " << esnekOlmayanCarpisma(v1, m1, v2, m2) << "\n\n";
		break;
	}

}


double BirBoyuttaCarpisma::esnekOlmayanCarpisma(double v1, double m1, double v2, double m2) {
	return (((m1 * v1) + (m2 * v2)) / (m1 + m2));
}

double BirBoyuttaCarpisma::esnekCarpismaV1(double v1, double m1, double v2, double m2) {
	return (((m1 - m2) * v1 + 2 * m2 * v2) / (m1 + m2));
}

double BirBoyuttaCarpisma::esnekCarpismaV2(double v1, double m1, double v2, double m2) {
	return (((m2 - m1) * v2 + 2 * m1 * v1) / (m1 + m2));
}