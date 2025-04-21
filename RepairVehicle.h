/**
 * RepairVehicle.h
 *
 * Derived class from Vehicle.
 * Represents a specific vehicle undergoing repairs and overrides input/output methods.
 */

#ifndef REPAIRVEHICLE_H
#define REPAIRVEHICLE_H

#include "Vehicle.h"

class RepairVehicle : public Vehicle {
public:
    RepairVehicle() = default;

    // Gathers repair-specific input from the user
    void input() override;

    // Displays the repair-specific vehicle info
    void display(int index) const override;

    // Converts object data to a string for file writing
    std::string toFileString() const override;

    // Populates object from a string read from a file
    void fromFileString(const std::string& data) override;
};

#endif
