#include <iostream>
#include "Kinematics.h"
#include "Dynamics.h"
#include "Energy.h"
#include "Electricity.h"

void showMainMenu() {
    std::cout << "\n========================================\n";
    std::cout << "         FIZIK HESAP MAKINESI\n";
    std::cout << "========================================\n";
    std::cout << "1. Kinematik (Hareket) Hesaplamalari\n";
    std::cout << "2. Dinamik (Kuvvet) Hesaplamalari\n";
    std::cout << "3. Enerji ve Is Hesaplamalari\n";
    std::cout << "4. Elektrik Hesaplamalari\n";
    std::cout << "0. Cikis\n";
    std::cout << "----------------------------------------\n";
    std::cout << "Seciminiz: ";
}

int main() {
    Kinematics kinematics;
    Dynamics dynamics;
    Energy energy;
    Electricity electricity;

    int choice;
    do {
        showMainMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            kinematics.run();
            break;
        case 2:
            dynamics.run();
            break;
        case 3:
            energy.run();
            break;
        case 4:
            electricity.run();
            break;
        case 0:
            std::cout << "\nProgramdan cikiliyor. Hoscakalin!\n";
            break;
        default:
            std::cout << "\nGecersiz secim! Lutfen 0-4 arasi bir sayi girin.\n";
        }
    } while (choice != 0);

    return 0;
}