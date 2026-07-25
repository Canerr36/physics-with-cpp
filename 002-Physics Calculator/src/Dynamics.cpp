#include <iostream>
#include "Dynamics.h"

void Dynamics::run() {
    int choice;
    do {
        std::cout << "\n--- Dinamik (Kuvvet) Hesaplamalari ---\n";
        std::cout << "1. Kuvvet Hesapla       (F = m*a)\n";
        std::cout << "2. Agirlik Hesapla      (W = m*g)\n";
        std::cout << "3. Momentum Hesapla     (p = m*v)\n";
        std::cout << "4. Surtunme Kuvveti     (f = mu*N)\n";
        std::cout << "5. Merkezcil Kuvvet     (Fc = m*v^2 / r)\n";
        std::cout << "0. Ana Menuye Don\n";
        std::cout << "Seciminiz: ";
        std::cin >> choice;

        double m, a, v, mu, N, r;

        switch (choice) {
        case 1:
            std::cout << "Kutle (kg): "; std::cin >> m;
            std::cout << "Ivme (m/s^2): "; std::cin >> a;
            std::cout << "Sonuc -> Kuvvet: " << calculateForce(m, a) << " N\n";
            break;

        case 2:
            std::cout << "Kutle (kg): "; std::cin >> m;
            std::cout << "Sonuc -> Agirlik: " << calculateWeight(m) << " N\n";
            break;

        case 3:
            std::cout << "Kutle (kg): "; std::cin >> m;
            std::cout << "Hiz (m/s): "; std::cin >> v;
            std::cout << "Sonuc -> Momentum: " << calculateMomentum(m, v) << " kg*m/s\n";
            break;

        case 4:
            std::cout << "Surtunme katsayisi (mu): "; std::cin >> mu;
            std::cout << "Normal kuvvet (N): "; std::cin >> N;
            std::cout << "Sonuc -> Surtunme kuvveti: " << calculateFriction(mu, N) << " N\n";
            break;

        case 5:
            std::cout << "Kutle (kg): "; std::cin >> m;
            std::cout << "Hiz (m/s): "; std::cin >> v;
            std::cout << "Yaricap (m): "; std::cin >> r;
            std::cout << "Sonuc -> Merkezcil kuvvet: " << calculateCentripetalForce(m, v, r) << " N\n";
            break;

        case 0:
            std::cout << "Ana menuye donuluyor...\n";
            break;

        default:
            std::cout << "Gecersiz secim! Tekrar deneyin.\n";
        }
    } while (choice != 0);
}

double Dynamics::calculateForce(double mass, double acceleration) {
    return mass * acceleration;
}

double Dynamics::calculateWeight(double mass) {
    const double g = 9.81;
    return mass * g;
}

double Dynamics::calculateMomentum(double mass, double velocity) {
    return mass * velocity;
}

double Dynamics::calculateFriction(double mu, double normalForce) {
    return mu * normalForce;
}

double Dynamics::calculateCentripetalForce(double mass, double velocity, double radius) {
    return (mass * velocity * velocity) / radius;
}