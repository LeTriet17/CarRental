//
// Created by jaylong on 1/22/22.
//

#include "inventory.h"

std::list<Vehicle*> VehicleInventory::searchByType(VehicleType type) {
    std::list<Vehicle*> result;
    std::cout<<"Searching for vehicles of type "<<type<<std::endl;
    for (auto &vehicle: totalVehicles) {
        if ((*vehicle).getType() == type) {
            result.push_back(vehicle);
        }
    }
    return result;
}

std::list<Vehicle*> VehicleInventory::searchByModel(VehicleType type, int model) {
    std::list<Vehicle*> result;
    for (auto &vehicle: totalVehicles) {
        if ((*vehicle).getType() == type && (int) (*vehicle).getModel() == model) {
            result.push_back(vehicle);
        }
    }
//    std::sort(result.begin(), result.end(), [](Vehicle *a, Vehicle *b) {
//        return (*a).getModel() < (*b).getModel();
//    });

    return result;
}

VehicleInventory::VehicleInventory(std::list<Vehicle*> &vehicles) {
    totalVehicles = vehicles;
    availableVehicles = addByStatus(VehicleStatus::AVAILABLE);
}

std::list<Vehicle*> VehicleInventory::addByStatus(VehicleStatus status) {
    std::list<Vehicle*> result;
    for (auto &vehicle: totalVehicles) {
        if ((*vehicle).getStatus() == status) {
            result.push_back(vehicle);
        }
    }
    return result;
}

std::list<Vehicle*> VehicleInventory::getAvailableVehicles() {
    return addByStatus(VehicleStatus::AVAILABLE);
}

std::list<Vehicle*> VehicleInventory::getRentedVehicles() {
    return addByStatus(VehicleStatus::BEING_SERVICED);
}

std::list<Vehicle*> VehicleInventory::getAllVehicles() {
    return totalVehicles;
}

std::list<Vehicle*> VehicleInventory::searchByCapacity(int capacity) {
    std::list<Vehicle*> result;
    for (auto &vehicle: totalVehicles) {
        if ((*vehicle).getCapacity() <= capacity) {
            result.push_back(vehicle);
        }
    }
//    std::sort(result.begin(), result.end(), [](Vehicle *v1, Vehicle *v2) {
//        return (*v1).getCapacity() < (*v2).getCapacity();
//    });
    return result;
}

void VehicleInventory::serviceFleet() {
    for (auto &vehicle: totalVehicles) {
        vehicle->serviceEngine();
        vehicle->serviceTransmission();
        vehicle->serviceTires();
    }
}
