#pragma once
#ifndef DYNAMICS_H
#define DYNAMICS_H

class Dynamics {
public:
    void run();

private:
    double calculateForce(double mass, double acceleration);
    double calculateWeight(double mass);
    double calculateMomentum(double mass, double velocity);
    double calculateFriction(double mu, double normalForce);
    double calculateCentripetalForce(double mass, double velocity, double radius);
};

#endif // DYNAMICS_H