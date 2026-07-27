#include <iostream> 
#include "uzunluk.h"


void Uzunluk::run() {
    int choice;
    double value;
    std::cout << "\n-- Uzunluk Donusumu --\n";
    std::cout << "1. km -> mil\n";
    std::cout << "2. mil -> km\n";
    std::cout << "3. metre -> feet\n";
    std::cout << "4. feet -> metre\n";
    std::cout << "0. Geri\n";
    std::cout << "Seciminiz: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        std::cout << "km: "; std::cin >> value;
        std::cout << "Sonuc: " << kmToMiles(value) << " mil\n";
        break;
    case 2:
        std::cout << "mil: "; std::cin >> value;
        std::cout << "Sonuc: " << milesToKm(value) << " km\n";
        break;
    case 3:
        std::cout << "metre: "; std::cin >> value;
        std::cout << "Sonuc: " << meterToFeet(value) << " feet\n";
        break;
    case 4:
        std::cout << "feet: "; std::cin >> value;
        std::cout << "Sonuc: " << feetToMeter(value) << " metre\n";
        break;
    case 0:
        break;
    default:
        std::cout << "Gecersiz secim!\n";
    }
};



double Uzunluk::kmToMiles(double km) { 
    return km * 0.621371; 
}

double Uzunluk::milesToKm(double miles) { 
    return miles / 0.621371; 
}

double Uzunluk::meterToFeet(double meter) {
    return meter * 3.28084;
}

double Uzunluk::feetToMeter(double feet) {
    return feet / 3.28084; 
}




