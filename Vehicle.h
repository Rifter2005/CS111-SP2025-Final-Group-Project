/**
 * Vehicle.h
 *
 * Base class for representing a vehicle in the auto repair database.
 * Provides virtual methods for input/output and basic vehicle info storage.
 */

#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
protected:
    std::string vin, licensePlate, model, color, damage;
    int year;
    float repairCost;
    int repairHours;
    bool isComplete;

public:
    Vehicle() = default;
    virtual ~Vehicle() = default;

    // Prompts user to input vehicle details
    virtual void input();

    // Displays vehicle details with index
    virtual void display(int index) const;

    // Converts vehicle data to a string format for file storage
    virtual std::string toFileString() const;

    // Parses vehicle data from a string (used when loading from file)
    virtual void fromFileString(const std::string& data);

    bool getRepairStatus() const;
    void setRepairStatus(bool status);
};

#endif
