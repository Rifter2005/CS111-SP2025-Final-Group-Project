#include "VehicleDatabase.h"
#include "Exceptions.h"
#include <iostream>
#include <fstream>

VehicleDatabase::VehicleDatabase() {
    loadFromFile();
}

void VehicleDatabase::addVehicle() {
    RepairVehicle v;
    v.input();                 // Gather data
    vehicles.push_back(v);    // Store in memory
    saveToFile();             // Write to file
}

void VehicleDatabase::viewVehicles() const {
    if (vehicles.empty()) std::cout << "No vehicles in the database.\n";
    for (size_t i = 0; i < vehicles.size(); ++i)
        vehicles[i].display(i);
}

void VehicleDatabase::editVehicle() {
    viewVehicles();
    std::cout << "Enter index to edit: ";
    int idx; std::cin >> idx; std::cin.ignore();

    if (idx < 0 || idx >= vehicles.size()) throw InvalidIndexException();

    std::cout << "Are you sure? (y/n): ";
    char confirm; std::cin >> confirm; std::cin.ignore();

    if (confirm == 'y' || confirm == 'Y') {
        vehicles[idx].input();  // Replace data
        saveToFile();           // Save change
    }
}

void VehicleDatabase::deleteVehicle() {
    viewVehicles();
    std::cout << "Enter index to delete: ";
    int idx; std::cin >> idx; std::cin.ignore();
    if (idx < 0 || idx >= vehicles.size()) throw InvalidIndexException();

    std::cout << "Are you sure? (y/n): ";
    char confirm; std::cin >> confirm; std::cin.ignore();

    if (confirm == 'y' || confirm == 'Y') {
        vehicles.erase(vehicles.begin() + idx);  // Delete vehicle
        saveToFile();                            // Update file
    }
}

void VehicleDatabase::saveToFile() const {
    std::ofstream file(filename);
    for (const auto& v : vehicles)
        file << v.toFileString() << '\n';  // Save each vehicle
}

void VehicleDatabase::loadFromFile() {
    vehicles.clear();
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        RepairVehicle v;
        v.fromFileString(line);  // Load each vehicle
        vehicles.push_back(v);
    }
}

void VehicleDatabase::advancedSettings() {
    int choice;
    std::cout << "\n--- Advanced Settings ---\n";
    std::cout << "1. Wipe Entire Database\n";
    std::cout << "2. Go Back\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;
    std::cin.ignore();

    if (choice == 1) {
        std::cout << "Are you sure you want to erase ALL data? (y/n): ";
        char confirm;
        std::cin >> confirm;
        std::cin.ignore();

        if (confirm == 'y' || confirm == 'Y') {
            vehicles.clear();
            saveToFile();
            std::cout << "Database has been wiped.\n";
        }
        else {
            std::cout << "Wipe canceled.\n";
        }
    }
    else if (choice != 2) {
        std::cout << "Invalid option.\n";
    }
}
