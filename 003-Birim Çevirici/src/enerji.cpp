#include <iostream>
#include "enerji.h"



void Enerji::run() {
    int choice;
    double value;
    std::cout << "\n-- Enerji Donusumu --\n";
    std::cout << "1. joule -> kalori\n";
    std::cout << "2. kalori -> joule\n";
    std::cout << "0. Geri\n";
    std::cout << "Seciminiz: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        std::cout << "joule: "; std::cin >> value;
        std::cout << "Sonuc: " << joulesToCalories(value) << " kalori\n";
        break;
    case 2:
        std::cout << "kalori: "; std::cin >> value;
        std::cout << "Sonuc: " << caloriesToJoules(value) << " joule\n";
        break;
    case 0:
        break;
    default:
        std::cout << "Gecersiz secim!\n";
    }
}

double Enerji::joulesToCalories(double joules) {
    return joules / 4.184;
}
double Enerji::caloriesToJoules(double calories) {
    return calories * 4.184; 
}