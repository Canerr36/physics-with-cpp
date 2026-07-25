#pragma once
#ifndef ENERGY_H
#define ENERGY_H

class Energy {
public:
    void run();

private:
    double calculateKineticEnergy(double mass, double velocity);
    double calculatePotentialEnergy(double mass, double height);
    double calculateElasticPotentialEnergy(double k, double x);
    double calculateWork(double force, double distance);
    double calculatePower(double work, double time);
};

#endif // ENERGY_H