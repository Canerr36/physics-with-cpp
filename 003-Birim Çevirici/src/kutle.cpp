#include <iostream> 
#include "kutle.h"




void Kutle::run() {
    int choice;
    double value;
    std::cout << "\n-- Kutle Donusumu --\n";
    std::cout << "1. kg -> pound\n";
    std::cout << "2. pound -> kg\n";
    std::cout << "0. Geri\n";
    std::cout << "Seciminiz: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        std::cout << "kg: "; std::cin >> value;
        std::cout << "Sonuc: " << kgToPound(value) << " pound\n";
        break;
    case 2:
        std::cout << "pound: "; std::cin >> value;
        std::cout << "Sonuc: " << poundToKg(value) << " kg\n";
        break;
    case 0:
        break;
    default:
        std::cout << "Gecersiz secim!\n";
    }
}

double Kutle::kgToPound(double kg) { 
    return kg * 2.20462;
}

double Kutle::poundToKg(double pound) { 
    return pound / 2.20462; 
}
