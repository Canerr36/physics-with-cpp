#include "Simulation.h"
#include <cmath>

Simulation::Simulation(double G_, double softening_)
    : G(G_), softening(softening_) {
}

void Simulation::addBody(const Body& body) {
    bodies.push_back(body);
}

// Her cift cisim arasindaki yercekimi kuvvetinden dogan ivmeyi hesaplar.
// N cisim icin bu O(N^2) bir islemdir; N buyudukce (orn. binlerce cisim)
// Barnes-Hut agaci gibi daha hizli yontemler gerekir.
void Simulation::computeAccelerations() {
    for (auto& b : bodies) {
        b.acceleration = Vector3(0, 0, 0);
    }

    for (size_t i = 0; i < bodies.size(); ++i) {
        for (size_t j = i + 1; j < bodies.size(); ++j) {
            Vector3 diff = bodies[j].position - bodies[i].position;
            double distSq = diff.lengthSquared() + softening * softening;
            double dist = std::sqrt(distSq);
            double forceMag = G / (distSq * dist); // = G / dist^3

            // Newton'un ucuncu yasasi: iki cisme ters yonde esit kuvvet
            bodies[i].acceleration += diff * (forceMag * bodies[j].mass);
            bodies[j].acceleration += diff * (-forceMag * bodies[i].mass);
        }
    }
}

// Velocity Verlet (Leapfrog) integrasyonu: basit Euler'e gore
// enerjiyi cok daha iyi korur ve yorunge simulasyonlari icin standarttir.
void Simulation::step(double dt) {
    computeAccelerations();

    std::vector<Vector3> oldAcc;
    oldAcc.reserve(bodies.size());
    for (auto& b : bodies) oldAcc.push_back(b.acceleration);

    for (size_t i = 0; i < bodies.size(); ++i) {
        bodies[i].position += bodies[i].velocity * dt + oldAcc[i] * (0.5 * dt * dt);
    }

    computeAccelerations();

    for (size_t i = 0; i < bodies.size(); ++i) {
        bodies[i].velocity += (oldAcc[i] + bodies[i].acceleration) * (0.5 * dt);
    }
}