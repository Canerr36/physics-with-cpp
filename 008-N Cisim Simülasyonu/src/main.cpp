#include <iostream>
#include <fstream>
#include "Simulation.h"

int main() {
    // "Toy" (oyuncak) birim sistemi: G = 1, kutle/mesafe/zaman keyfi birimlerde.
    // Gercek astronomik birimler istersen G, kutleleri ve mesafeleri
    // SI ya da AU-gunes kutlesi-gun sistemine gore olceklemen gerekir.
    Simulation sim(/*G=*/1.0, /*softening=*/1e-3);

    sim.addBody(Body("Merkez", 1000.0, Vector3(0, 0, 0), Vector3(0, 0, 0)));
    sim.addBody(Body("Gezegen1", 1.0, Vector3(10, 0, 0), Vector3(0, 10.0, 0)));
    sim.addBody(Body("Gezegen2", 5.0, Vector3(0, 20, 0), Vector3(-7.0, 0, 0)));

    std::ofstream out("orbits.csv");
    out << "step,name,x,y,z\n";

    const double dt = 0.001;
    const int steps = 20000;

    for (int s = 0; s < steps; ++s) {
        sim.step(dt);

        // Her adimi degil, her 50 adimda bir kaydet (dosya kucuk kalsin)
        if (s % 50 == 0) {
            for (const auto& b : sim.getBodies()) {
                out << s << "," << b.name << "," << b.position.x << ","
                    << b.position.y << "," << b.position.z << "\n";
            }
        }
    }

    out.close();
    std::cout << "Simulasyon tamamlandi. Sonuclar orbits.csv dosyasina yazildi.\n";
    return 0;
}