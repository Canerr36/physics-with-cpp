#pragma once
#include <string>
#include "Vector3.h"

// Uzaydaki tek bir cismi temsil eder: kutle, konum, hiz ve ivme
class Body {
public:
    std::string name;
    double mass;
    Vector3 position;
    Vector3 velocity;
    Vector3 acceleration;

    Body(std::string name_, double mass_, Vector3 position_, Vector3 velocity_)
        : name(std::move(name_)), mass(mass_),
        position(position_), velocity(velocity_),
        acceleration(0, 0, 0) {
    }
};