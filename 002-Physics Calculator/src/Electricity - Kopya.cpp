#include <iostream>
#include "Electricity.h"

void Electricity::run() {
    int choice;
    do {
        std::cout << "\n--- Elektrik Hesaplamalari ---\n";
        std::cout << "1. Gerilim Hesapla        (V = I*R)\n";
        std::cout << "2. Akim Hesapla           (I = V/R)\n";
        std::cout << "3. Direnc Hesapla         (R = V/I)\n";
        std::cout << "4. Elektriksel Guc        (P = V*I)\n";
        std::cout << "5. Seri Direnc            (R = R1+R2)\n";
        std::cout << "6. Paralel Direnc         (R = (R1*R2)/(R1+R2))\n";
        std::cout << "0. Ana Menuye Don\n";
        std::cout << "Seciminiz: ";
        std::cin >> choice;

        double V, I, R, r1, r2;

        switch (choice) {
        case 1:
            std::cout << "Akim (A): "; std::cin >> I;
            std::cout << "Direnc (ohm): "; std::cin >> R;
            std::cout << "Sonuc -> Gerilim: " << calculateVoltage(I, R) << " V\n";
            break;

        case 2:
            std::cout << "Gerilim (V): "; std::cin >> V;
            std::cout << "Direnc (ohm): "; std::cin >> R;
            std::cout << "Sonuc -> Akim: " << calculateCurrent(V, R) << " A\n";
            break;

        case 3:
            std::cout << "Gerilim (V): "; std::cin >> V;
            std::cout << "Akim (A): "; std::cin >> I;
            std::cout << "Sonuc -> Direnc: " << calculateResistance(V, I) << " ohm\n";
            break;

        case 4:
            std::cout << "Gerilim (V): "; std::cin >> V;
            std::cout << "Akim (A): "; std::cin >> I;
            std::cout << "Sonuc -> Guc: " << calculateElectricalPower(V, I) << " W\n";
            break;

        case 5:
            std::cout << "R1 (ohm): "; std::cin >> r1;
            std::cout << "R2 (ohm): "; std::cin >> r2;
            std::cout << "Sonuc -> Toplam direnc: " << seriesResistance(r1, r2) << " ohm\n";
            break;

        case 6:
            std::cout << "R1 (ohm): "; std::cin >> r1;
            std::cout << "R2 (ohm): "; std::cin >> r2;
            std::cout << "Sonuc -> Toplam direnc: " << parallelResistance(r1, r2) << " ohm\n";
            break;

        case 0:
            std::cout << "Ana menuye donuluyor...\n";
            break;

        default:
            std::cout << "Gecersiz secim! Tekrar deneyin.\n";
        }
    } while (choice != 0);
}

double Electricity::calculateVoltage(double current, double resistance) {
    return current * resistance;
}

double Electricity::calculateCurrent(double voltage, double resistance) {
    return voltage / resistance;
}

double Electricity::calculateResistance(double voltage, double current) {
    return voltage / current;
}

double Electricity::calculateElectricalPower(double voltage, double current) {
    return voltage * current;
}

double Electricity::seriesResistance(double r1, double r2) {
    return r1 + r2;
}

double Electricity::parallelResistance(double r1, double r2) {
    return (r1 * r2) / (r1 + r2);
}