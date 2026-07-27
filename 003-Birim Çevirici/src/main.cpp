#include <iostream>
#include "aci.h"
#include "enerji.h"
#include "hiz.h"
#include "kutle.h"
#include "sicaklik.h"
#include "uzunluk.h"

void showMainMenu() {
    std::cout << "\n--- Birim Donusturucu ---\n";
    std::cout << "1. Uzunluk    (km, mil, metre, feet)\n";
    std::cout << "2. Kutle      (kg, pound)\n";
    std::cout << "3. Hiz        (km/h, m/s)\n";
    std::cout << "4. Sicaklik   (Celsius, Fahrenheit, Kelvin)\n";
    std::cout << "5. Aci        (derece, radyan)\n";
    std::cout << "6. Enerji     (joule, kalori)\n";
    std::cout << "0. Ana Menuye Don\n";
    std::cout << "Seciminiz: ";
}

int main() {
    // Her fizik dali icin ayri bir nesne olusturuyoruz

    Enerji enerji;
    Aci aci;
    Hiz hiz;
    Kutle kutle;
    Sicaklik sicaklik;
    Uzunluk uzunluk;




    int choice;
    do {
        showMainMenu();
        std::cin >> choice;

        switch (choice) {
        case 1: uzunluk.run(); break;
        case 2: kutle.run(); break;
        case 3: hiz.run(); break;
        case 4: sicaklik.run(); break;
        case 5: aci.run(); break;
        case 6: enerji.run(); break;
        case 0:
            std::cout << "Ana menuye donuluyor...\n";
            break;
        default:
            std::cout << "Gecersiz secim! Tekrar deneyin.\n";
        }
    } while (choice != 0);
}