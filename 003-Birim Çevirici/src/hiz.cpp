#include <iostream> 
#include "hiz.h"



void Hiz::run() {
    int choice;
    double value;
    std::cout << "\n-- Hiz Donusumu --\n";
    std::cout << "1. km/h -> m/s\n";
    std::cout << "2. m/s -> km/h\n";
    std::cout << "0. Geri\n";
    std::cout << "Seciminiz: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        std::cout << "km/h: "; std::cin >> value;
        std::cout << "Sonuc: " << kmhToMs(value) << " m/s\n";
        break;
    case 2:
        std::cout << "m/s: "; std::cin >> value;
        std::cout << "Sonuc: " << msToKmh(value) << " km/h\n";
        break;
    case 0:
        break;
    default:
        std::cout << "Gecersiz secim!\n";
    }
}

double Hiz::kmhToMs(double kmh) {
    return kmh / 3.6; 
}

double Hiz::msToKmh(double ms) {
    return ms * 3.6;
}
