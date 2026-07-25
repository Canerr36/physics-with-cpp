#pragma once
#ifndef KINEMATICS_H
#define KINEMATICS_H

class Kinematics {
public:
    void run();
    double calculateVelocity(double distance, double time);
    double calculateAcceleration(double v0, double v1, double time);
    double calculateDisplacement(double v0, double a, double t);
    double calculateFinalVelocity(double v0, double a, double t);
    void projectileMotion(double v0, double angleDeg);
};

#endif // KINEMATICS_H