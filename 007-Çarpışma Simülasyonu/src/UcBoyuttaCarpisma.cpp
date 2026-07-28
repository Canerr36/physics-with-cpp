#include <iostream>
#include <cmath>
#include "UcBoyuttaCarpisma.h"

#define PI 3.14159265



void UcBoyuttaCarpisma::run() {

	int choice;
	double v1, m1, v2, m2;
	double alfa1, beta1, alfa2, beta2;
	double radyalalfa1, radyalbeta1, radyalalfa2, radyalbeta2;
	double v1x, v1y, v1z, v2x, v2y, v2z;


	std::cout << "---  Uc Boyutta Carpisma  ---\n\n";

	std::cout << "1-Esnek Carpisma\n";
	std::cout << "2-Esnek olmayan Carpisma\n";
	std::cout << "Carpisma turunu seciniz -> ";
	std::cin >> choice;

	std::cout << "Birinci cismin hizi    -> ";
	std::cin >> v1;
	std::cout << "Birinci cismin kutlesi -> ";
	std::cin >> m1;
	std::cout << "Birinci cismin x ekseni ile yaptigi aci (xy duzleminde) -> ";
	std::cin >> alfa1;
	std::cout << "Birinci cismin z ekseni ile yaptigi aci               -> ";
	std::cin >> beta1;
	std::cout << "\n";
	std::cout << "Ikinci cismin hizi     -> ";
	std::cin >> v2;
	std::cout << "Ikinci cismin kutlesi  -> ";
	std::cin >> m2;
	std::cout << "Ikinci cismin x ekseni ile yaptigi aci (xy duzleminde)  -> ";
	std::cin >> alfa2;
	std::cout << "Ikinci cismin z ekseni ile yaptigi aci                 -> ";
	std::cin >> beta2;
	std::cout << "\n";


	if (((choice == 1) || (choice == 2)) != 1) {
		std::cout << "Hatali giris yaptiniz \n";
		return;
	}

	radyalalfa1 = alfa1 * (PI / 180);
	radyalbeta1 = beta1 * (PI / 180);
	radyalalfa2 = alfa2 * (PI / 180);
	radyalbeta2 = beta2 * (PI / 180);

	v1x = v1 * sin(radyalbeta1) * cos(radyalalfa1);
	v1y = v1 * sin(radyalbeta1) * sin(radyalalfa1);
	v1z = v1 * cos(radyalbeta1);

	v2x = v2 * sin(radyalbeta2) * cos(radyalalfa2);
	v2y = v2 * sin(radyalbeta2) * sin(radyalalfa2);
	v2z = v2 * cos(radyalbeta2);

	switch (choice) {
	case 1:
		std::cout << "Carpisma Sonrasi  \n";
		std::cout << "Birinci Cismin Hizi  ->   Vx : " << esnekCarpismaV1(v1x, m1, v2x, m2)
			<< "   Vy : " << esnekCarpismaV1(v1y, m1, v2y, m2)
			<< "   Vz : " << esnekCarpismaV1(v1z, m1, v2z, m2) << "\n";
		std::cout << "Ikinci Cismin Hizi   ->   Vx : " << esnekCarpismaV2(v1x, m1, v2x, m2)
			<< "   Vy : " << esnekCarpismaV2(v1y, m1, v2y, m2)
			<< "   Vz : " << esnekCarpismaV2(v1z, m1, v2z, m2) << "\n\n";
		break;
	case 2:
		std::cout << "Capisma sonrasi cismin kutlesi -> " << m1 + m2 << "\n";
		std::cout << "Carpisma sonrasi cismin hizi   ->     Vx :  " << esnekOlmayanCarpisma(v1x, m1, v2x, m2)
			<< "   Vy : " << esnekOlmayanCarpisma(v1y, m1, v2y, m2)
			<< "   Vz : " << esnekOlmayanCarpisma(v1z, m1, v2z, m2) << "\n\n";
		break;
	}

}


double UcBoyuttaCarpisma::esnekOlmayanCarpisma(double v1, double m1, double v2, double m2) {
	return (((m1 * v1) + (m2 * v2)) / (m1 + m2));
}

double UcBoyuttaCarpisma::esnekCarpismaV1(double v1, double m1, double v2, double m2) {
	return (((m1 - m2) * v1 + 2 * m2 * v2) / (m1 + m2));
}

double UcBoyuttaCarpisma::esnekCarpismaV2(double v1, double m1, double v2, double m2) {
	return (((m2 - m1) * v2 + 2 * m1 * v1) / (m1 + m2));
}