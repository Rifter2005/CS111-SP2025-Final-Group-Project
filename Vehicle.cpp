#include "Vehicle.h"

// Base class stubs; overridden in derived class

void Vehicle::input() {
    // This method is overridden in derived class.
}

void Vehicle::display(int index) const {
    // This method is overridden in derived class.
}

std::string Vehicle::toFileString() const {
    return "";
}

void Vehicle::fromFileString(const std::string& data) {
    // Do nothing (abstract in practice)
}

bool Vehicle::getRepairStatus() const {
    return isComplete;
}

void Vehicle::setRepairStatus(bool status) {
    isComplete = status;
}
