#include <iostream>
#include "BirBoyuttaCarpisma.h"
#include "IkiBoyuttaHareket.h"
#include "UcBoyuttaCarpisma.h"



class MainMenu {
public:
	void run() {

		std::cout << "=================================\n";
		std::cout << "       Carpisma Simulatoru       \n";
		std::cout << "=================================\n\n";

		std::cout << "---  Boyutunuzu Seciniz ---\n";
		std::cout << "1 - Bir Boyutta Carpisma (x ekseninde)\n";
		std::cout << "2 - Iki Boyutta Carpisma (x-y ekseninde)\n";
		std::cout << "3 - Uc Boyutta Carpisma  (x-y-z ekseninde)\n";
		std::cout << "0 - programi kapatmak icin\n";
		std::cout << "seciminiz  -> ";

	}
};






int main() {
	int choice;

	BirBoyuttaCarpisma b1;
	IkiBoyuttaCarpisma b2;
	UcBoyuttaCarpisma b3;


	MainMenu mainMenu;
	do
	{
		mainMenu.run();
		std::cin >> choice;
		if (((choice == 1) || (choice == 2) || (choice == 3) || choice == 0) != 1) {
			std::cout << "Hatali giris yaptiniz \n\n";
			continue;
		}

		switch (choice) {
		case 1:
			b1.run();
			break;
		case 2:
			b2.run();
			break;
		case 3:
			b3.run();
			break;
		}

	} while (choice != 0);

	return 0;
}