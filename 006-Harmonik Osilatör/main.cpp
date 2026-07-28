// Euler vs RK4 - Sonumlu Yay-Kutle Sistemi (Damped Harmonic Oscillator)
// Denklem: m*x'' + c*x' + k*x = 0
// Ikinci derece denklemi iki adet birinci derece denkleme indirgiyoruz:
//   x' = v
//   v' = -(k/m)*x - (c/m)*v
//
// Amac: Ayni sistemi iki farkli sayisal yontemle cozup, enerji korunumu
// acisindan karsilastirmak. Euler zamanla enerji "sizdirir" (genlik buyur/kucul(ur)),
// RK4 cok daha kararli kalir.

#include <iostream>
#include <fstream>
#include <cmath>

// Sistem parametreleri
struct Parameters {
    double m = 1.0;   // kutle (kg)
    double k = 20.0;  // yay sabiti (N/m)
    double c = 0.5;   // sonum katsayisi (damping)
};

// Sistemin durumu: konum ve hiz
struct State {
    double x; // konum
    double v; // hiz
};

// Turev fonksiyonu: verilen duruma gore (x', v') dondurur
State derivative(const State& s, const Parameters& p) {
    State d;
    d.x = s.v;
    d.v = -(p.k / p.m) * s.x - (p.c / p.m) * s.v;
    return d;
}

// --- EULER YONTEMI ---
// Basit ama hatasi birikimli: sadece o anki egimi kullanarak bir adim atar.
State eulerStep(const State& s, const Parameters& p, double dt) {
    State d = derivative(s, p);
    State next;
    next.x = s.x + d.x * dt;
    next.v = s.v + d.v * dt;
    return next;
}

// --- RUNGE-KUTTA 4 (RK4) ---
// Bir adimda 4 farkli noktada egim hesaplayip agirlikli ortalama alir.
// Cok daha dogru, ama 4 kat daha fazla hesaplama gerektirir.
State rk4Step(const State& s, const Parameters& p, double dt) {
    State k1 = derivative(s, p);

    State s2 = { s.x + 0.5 * dt * k1.x, s.v + 0.5 * dt * k1.v };
    State k2 = derivative(s2, p);

    State s3 = { s.x + 0.5 * dt * k2.x, s.v + 0.5 * dt * k2.v };
    State k3 = derivative(s3, p);

    State s4 = { s.x + dt * k3.x, s.v + dt * k3.v };
    State k4 = derivative(s4, p);

    State next;
    next.x = s.x + (dt / 6.0) * (k1.x + 2 * k2.x + 2 * k3.x + k4.x);
    next.v = s.v + (dt / 6.0) * (k1.v + 2 * k2.v + 2 * k3.v + k4.v);
    return next;
}

// Toplam mekanik enerji: kinetik + potansiyel
double totalEnergy(const State& s, const Parameters& p) {
    double kinetic = 0.5 * p.m * s.v * s.v;
    double potential = 0.5 * p.k * s.x * s.x;
    return kinetic + potential;
}

int main() {
    Parameters p;
    double dt = 0.01;      // zaman adimi (kucuk tutarsan Euler de iyilesir - deneyerek gor)
    double t_max = 10.0;   // toplam simulasyon suresi

    State stateEuler{ 1.0, 0.0 }; // baslangic: 1 metre cekilmis, hiz sifir
    State stateRK4{ 1.0, 0.0 };

    std::ofstream out("sonuclar.csv");
    out << "t,x_euler,x_rk4,enerji_euler,enerji_rk4\n";

    for (double t = 0.0; t <= t_max; t += dt) {
        double eEuler = totalEnergy(stateEuler, p);
        double eRK4 = totalEnergy(stateRK4, p);

        out << t << "," << stateEuler.x << "," << stateRK4.x << ","
            << eEuler << "," << eRK4 << "\n";

        stateEuler = eulerStep(stateEuler, p, dt);
        stateRK4 = rk4Step(stateRK4, p, dt);
    }

    out.close();

    std::cout << "Simulasyon tamamlandi. sonuclar.csv dosyasina yazildi.\n";
    std::cout << "CSV'yi Excel ile actiginda:\n";
    std::cout << " - x_euler zamanla beklenenden farkli sonup (bazen enerji kazaniyormus gibi buyuyebilir)\n";
    std::cout << " - x_rk4 çok daha duzgun sonecek\n";
    std::cout << " - enerji_euler zamanla dalgalanacak, enerji_rk4 neredeyse sabit kalacak\n";

    return 0;
}