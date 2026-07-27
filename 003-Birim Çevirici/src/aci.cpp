#include <iostream> 
#include "aci.h"



void Aci::run() {
    int choice;
    double value;
    std::cout << "\n-- Aci Donusumu --\n";
    std::cout << "1. derece -> radyan\n";
    std::cout << "2. radyan -> derece\n";
    std::cout << "0. Geri\n";
    std::cout << "Seciminiz: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        std::cout << "derece: "; std::cin >> value;
        std::cout << "Sonuc: " << degreesToRadians(value) << " radyan\n";
        break;
    case 2:
        std::cout << "radyan: "; std::cin >> value;
        std::cout << "Sonuc: " << radiansToDegrees(value) << " derece\n";
        break;
    case 0:
        break;
    default:
        std::cout << "Gecersiz secim!\n";
    }
}

double Aci::degreesToRadians(double degrees) {
    const double PI = 3.14159265358979323846;
    return degrees * PI / 180.0;
}

double Aci::radiansToDegrees(double radians) {
    const double PI = 3.14159265358979323846;
    return radians * 180.0 / PI;
}