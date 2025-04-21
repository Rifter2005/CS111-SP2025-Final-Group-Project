#include "VehicleDatabase.h"
#include "Exceptions.h"
#include <iostream>

int main() {
    VehicleDatabase db;
    int choice;

    while (true) {
        std::cout << "\n--- Auto Repair Shop Menu ---\n";
        std::cout << "1. Add Vehicle\n";
        std::cout << "2. View Vehicles\n";
        std::cout << "3. Edit Vehicle\n";
        std::cout << "4. Delete Vehicle\n";
        std::cout << "5. Advanced Settings\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        try {
            switch (choice) {
            case 1: db.addVehicle(); break;
            case 2: db.viewVehicles(); break;
            case 3: db.editVehicle(); break;
            case 4: db.deleteVehicle(); break;
            case 5: db.advancedSettings(); break;
            case 6: return 0;
            default: std::cout << "Invalid choice!\n";
            }
        }
        catch (const InvalidIndexException& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
        catch (...) {
            std::cerr << "An unknown error occurred.\n";
        }
    }
}
