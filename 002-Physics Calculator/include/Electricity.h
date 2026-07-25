#pragma once
#ifndef ELECTRICITY_H
#define ELECTRICITY_H

class Electricity {
public:
    void run();

private:
    double calculateVoltage(double current, double resistance);
    double calculateCurrent(double voltage, double resistance);
    double calculateResistance(double voltage, double current);
    double calculateElectricalPower(double voltage, double current);
    double seriesResistance(double r1, double r2);
    double parallelResistance(double r1, double r2);
};

#endif // ELECTRICITY_H