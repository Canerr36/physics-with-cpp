#include <iostream>
#include "sicaklik.h"




void Sicaklik::run() {
    int choice;
    double value;
    std::cout << "\n-- Sicaklik Donusumu --\n";
    std::cout << "1. Celsius -> Fahrenheit\n";
    std::cout << "2. Fahrenheit -> Celsius\n";
    std::cout << "3. Celsius -> Kelvin\n";
    std::cout << "4. Kelvin -> Celsius\n";
    std::cout << "0. Geri\n";
    std::cout << "Seciminiz: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        std::cout << "Celsius: "; std::cin >> value;
        std::cout << "Sonuc: " << celsiusToFahrenheit(value) << " F\n";
        break;
    case 2:
        std::cout << "Fahrenheit: "; std::cin >> value;
        std::cout << "Sonuc: " << fahrenheitToCelsius(value) << " C\n";
        break;
    case 3:
        std::cout << "Celsius: "; std::cin >> value;
        std::cout << "Sonuc: " << celsiusToKelvin(value) << " K\n";
        break;
    case 4:
        std::cout << "Kelvin: "; std::cin >> value;
        std::cout << "Sonuc: " << kelvinToCelsius(value) << " C\n";
        break;
    case 0:
        break;
    default:
        std::cout << "Gecersiz secim!\n";
    }
}

double Sicaklik::celsiusToFahrenheit(double celsius) { 
    return celsius * 9.0 / 5.0 + 32.0; 
}

double Sicaklik::fahrenheitToCelsius(double fahrenheit) { 
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double Sicaklik::celsiusToKelvin(double celsius) { 
    return celsius + 273.15; 
}

double Sicaklik::kelvinToCelsius(double kelvin) {
    return kelvin - 273.15; 
}
