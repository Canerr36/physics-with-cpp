#include <iostream>
#include <complex>
#include <cmath>

int main() {
    using Complex = std::complex<double>;

    // psi = a|0> + b|1>
    Complex alpha(1.0 / std::sqrt(2), 0.0);
    Complex beta(1.0 / std::sqrt(2), 0.0);

    // Normalizasyon  |α|^2 + |β|^2 = 1
    double norm = std::norm(alpha) + std::norm(beta);
    std::cout << "Norm: " << norm << "\n";

    // Ölçüm olasılıkları
    double p0 = std::norm(alpha); // |0> olma olasiligi
    double p1 = std::norm(beta);  // |1> olma olasiligi
    std::cout << "P(0) = " << p0 << ", P(1) = " << p1 << "\n";
}