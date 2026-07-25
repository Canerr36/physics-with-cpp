#include <iostream>
#include <cmath>
#include "Kinematics.h"

#define M_PI 3.14159265

void Kinematics::run() {
    int choice;
    do {
        std::cout << "\n--- Kinematik (Hareket) Hesaplamalari ---\n";
        std::cout << "1. Hiz Hesapla            (v = x / t)\n";
        std::cout << "2. Ivme Hesapla            (a = (v1-v0) / t)\n";
        std::cout << "3. Yer Degistirme Hesapla  (x = v0*t + 0.5*a*t^2)\n";
        std::cout << "4. Son Hiz Hesapla         (v = v0 + a*t)\n";
        std::cout << "5. Egik Atis Hesapla       (Menzil, Yukseklik, Sure)\n";
        std::cout << "0. Ana Menuye Don\n";
        std::cout << "Seciminiz: ";
        std::cin >> choice;

        double x, t, v0, v1, a, angle;

        switch (choice) {
        case 1:
            std::cout << "Mesafe (m): "; std::cin >> x;
            std::cout << "Zaman (s): "; std::cin >> t;
            std::cout << "Sonuc -> Hiz: " << calculateVelocity(x, t) << " m/s\n";
            break;

        case 2:
            std::cout << "Ilk hiz (m/s): "; std::cin >> v0;
            std::cout << "Son hiz (m/s): "; std::cin >> v1;
            std::cout << "Zaman (s): "; std::cin >> t;
            std::cout << "Sonuc -> Ivme: " << calculateAcceleration(v0, v1, t) << " m/s^2\n";
            break;

        case 3:
            std::cout << "Ilk hiz (m/s): "; std::cin >> v0;
            std::cout << "Ivme (m/s^2): "; std::cin >> a;
            std::cout << "Zaman (s): "; std::cin >> t;
            std::cout << "Sonuc -> Yer degistirme: " << calculateDisplacement(v0, a, t) << " m\n";
            break;

        case 4:
            std::cout << "Ilk hiz (m/s): "; std::cin >> v0;
            std::cout << "Ivme (m/s^2): "; std::cin >> a;
            std::cout << "Zaman (s): "; std::cin >> t;
            std::cout << "Sonuc -> Son hiz: " << calculateFinalVelocity(v0, a, t) << " m/s\n";
            break;

        case 5:
            std::cout << "Firlatma hizi (m/s): "; std::cin >> v0;
            std::cout << "Acisi (derece): "; std::cin >> angle;
            projectileMotion(v0, angle);
            break;

        case 0:
            std::cout << "Ana menuye donuluyor...\n";
            break;

        default:
            std::cout << "Gecersiz secim! Tekrar deneyin.\n";
        }
    } while (choice != 0);
}

double Kinematics::calculateVelocity(double distance, double time) {
    return distance / time;
}

double Kinematics::calculateAcceleration(double v0, double v1, double time) {
    return (v1 - v0) / time;
}

double Kinematics::calculateDisplacement(double v0, double a, double t) {
    return v0 * t + 0.5 * a * t * t;
}

double Kinematics::calculateFinalVelocity(double v0, double a, double t) {
    return v0 + a * t;
}

void Kinematics::projectileMotion(double v0, double angleDeg) {
    const double g = 9.81;
    double angleRad = angleDeg * M_PI / 180.0;

    double timeOfFlight = (2 * v0 * sin(angleRad)) / g;
    double maxHeight = (v0 * v0 * sin(angleRad) * sin(angleRad)) / (2 * g);
    double range = (v0 * v0 * sin(2 * angleRad)) / g;

    std::cout << "Ucus Suresi: " << timeOfFlight << " s\n";
    std::cout << "Maksimum Yukseklik: " << maxHeight << " m\n";
    std::cout << "Menzil: " << range << " m\n";
}