#pragma once
#include <vector>
#include "Body.h"

// Tum cisimleri tutar, aralarindaki yercekimi kuvvetini hesaplar
// ve zaman icinde konumlarini gunceller (Velocity Verlet integrasyonu)
class Simulation {
public:
    Simulation(double G, double softening);

    void addBody(const Body& body);
    void step(double dt);
    const std::vector<Body>& getBodies() const { return bodies; }

private:
    std::vector<Body> bodies;
    double G;          // yercekimi sabiti (secilen birim sistemine gore)
    double softening;  // yumusatma parametresi: cisimler cok yaklasinca
    // kuvvetin sonsuza gitmesini (sayisal patlamayi) engeller

    void computeAccelerations();
};