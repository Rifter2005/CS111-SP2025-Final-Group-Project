#include "RepairVehicle.h"
#include <iostream>
#include <sstream>

void RepairVehicle::input() {
    std::cout << "Enter VIN: "; std::getline(std::cin, vin);
    std::cout << "Enter License Plate: "; std::getline(std::cin, licensePlate);
    std::cout << "Enter Model: "; std::getline(std::cin, model);
    std::cout << "Enter Year: "; std::cin >> year; std::cin.ignore();
    std::cout << "Enter Color: "; std::getline(std::cin, color);
    std::cout << "Enter Extent of Damage: "; std::getline(std::cin, damage);
    std::cout << "Enter Repair Cost: "; std::cin >> repairCost;
    std::cout << "Enter Estimated Repair Hours: "; std::cin >> repairHours;
    std::cout << "Is Repair Complete? (1 for Yes, 0 for No): "; std::cin >> isComplete; std::cin.ignore();
}

void RepairVehicle::display(int index) const {
    std::cout << "\nVehicle [" << index << "]\n"
        << " VIN: " << vin << "\n License Plate: " << licensePlate
        << "\n Model: " << model << "\n Year: " << year
        << "\n Color: " << color << "\n Damage: " << damage
        << "\n Cost: $" << repairCost << "\n Repair Time: " << repairHours << " hours";

    int days = repairHours / 8;
    std::cout << " (~" << (days < 7 ? days : days / 7) << (days < 7 ? " days" : " weeks") << ")\n"
        << " Completed: " << (isComplete ? "Yes" : "No") << "\n";
}

std::string RepairVehicle::toFileString() const {
    return vin + "|" + licensePlate + "|" + model + "|" + std::to_string(year) + "|" + color + "|" +
        damage + "|" + std::to_string(repairCost) + "|" + std::to_string(repairHours) + "|" +
        (isComplete ? "1" : "0");
}

void RepairVehicle::fromFileString(const std::string& data) {
    std::stringstream ss(data);
    std::getline(ss, vin, '|');
    std::getline(ss, licensePlate, '|');
    std::getline(ss, model, '|');
    ss >> year; ss.ignore();
    std::getline(ss, color, '|');
    std::getline(ss, damage, '|');
    ss >> repairCost; ss.ignore();
    ss >> repairHours; ss.ignore();
    int complete;
    ss >> complete;
    isComplete = complete;
}
