/**
 * VehicleDatabase.h
 *
 * Manages a collection of RepairVehicle objects.
 * Handles all interaction with the vehicle "database" (text file),
 * including add, edit, delete, view, and advanced settings.
 */

#ifndef VEHICLEDATABASE_H
#define VEHICLEDATABASE_H

#include "RepairVehicle.h"
#include <vector>

class VehicleDatabase {
private:
    std::vector<RepairVehicle> vehicles;
    const std::string filename = "vehicles.txt";

public:
    VehicleDatabase();
    void addVehicle();           // Add a new vehicle
    void viewVehicles() const;   // Display all vehicles
    void editVehicle();          // Edit vehicle details
    void deleteVehicle();        // Remove a vehicle
    void saveToFile() const;     // Save current list to file
    void loadFromFile();         // Load list from file
    void advancedSettings();     // Wipe DB or go back
};

#endif
