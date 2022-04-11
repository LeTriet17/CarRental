//
// Created by jaylong on 1/22/22.
//

#include "user.h"

#include <utility>

Account::Account(int id, std::string password, Person person) {
    this->id = id;
    createAccount(std::move(password), std::move(person));
}

void Account::createAccount(std::string password, Person person) {
    this->password = std::move(password);
    this->person = std::move(person);
}

void Account::UpdateAccount(std::string password, Person person) {
    createAccount(std::move(password), std::move(person));
}


void Account::getAvailableVehicles(VehicleInventory &vehicleInventory) {
    std::list<Vehicle *> availableVehicles = vehicleInventory.getAvailableVehicles();
    printAvailableVehicles(availableVehicles);

}

void Account::searchInventoryByType(VehicleInventory &inventory, VehicleType type) {
    std::list<Vehicle *> vehicles = inventory.searchByType(type);
    printAvailableVehicles(vehicles);
}

void Account::printAvailableVehicles(std::list<Vehicle *> &availableVehicles) {
    for (auto &vehicle: availableVehicles) {
        std::cout << (*vehicle).getLicenseNumber() << " " << (*vehicle).getType() << " " << (*vehicle).getVehicleModel()
                  << " "
                  << (*vehicle).getMileage() << std::endl;
    }

}

void Account::searchInventoryByModel(VehicleInventory &inventory, VehicleType type, int model) {
    std::list<Vehicle *> vehicles = inventory.searchByModel(type, model);
    printAvailableVehicles(vehicles);
}

void Account::searchInventoryByCapacity(VehicleInventory &inventory, int capacity) {
    std::list<Vehicle *> vehicles = inventory.searchByCapacity(capacity);
    printAvailableVehicles(vehicles);
}

void Account::showInventory(VehicleInventory &inventory) {
    std::list<Vehicle *> vehicles = inventory.getAllVehicles();
    printAvailableVehicles(vehicles);
}

void Account::showRentedVehicles(VehicleInventory &inventory) {
    std::list<Vehicle *> vehicles = inventory.getRentedVehicles();
    printAvailableVehicles(vehicles);
}

bool Account::resetPassword(std::string newPassword) {
    this->password = std::move(newPassword);
    return true;
}


std::list<VehicleReservation> Customer::getReservations(VehicleInventory &inventory) {
    std::list<VehicleReservation> reservations;
    showInventory(inventory);
    while (true) {
        std::cout << "Enter vehicle license number: (q to quit)" << std::endl;
        std::string licenseNumber;
        std::cin >> licenseNumber;
        if (licenseNumber == "q") {
            break;
        }
        bool isRented = false;
        for (auto &vehicle: inventory.getAvailableVehicles()) {
            if (vehicle->getLicenseNumber() == licenseNumber) {
                vehicle->reserveVehicle();
                isRented = true;
            }
        }
        if (!isRented) {
            std::cout << "Vehicle not found or being used" << std::endl;
        } else {
            std::cout << "Enter start date: (Ex: 2018 01 01) ";
            int startYear, startMonth, startDay;
            std::cin >> startYear >> startMonth >> startDay;
            Date startDate(startYear, startMonth, startDay);
            std::cout << "Enter end date: (Ex: 2018 01 01) ";
            int endYear, endMonth, endDay;
            std::cin >> endYear >> endMonth >> endDay;
            Date endDate(endYear, endMonth, endDay);
            std::cout << "Enter pickup location: ";
            std::string pickupLocation;
            std::cin >> pickupLocation;
            std::cout << "Enter drop off location: ";
            std::string dropOffLocation;
            std::cin >> dropOffLocation;
            VehicleReservation reservation(licenseNumber, startDate, endDate, pickupLocation, dropOffLocation);
            reservations.push_back(reservation);
        }
    }
    this->userReservation = reservations;
    return reservations;
}

Customer::Customer(int id, std::string password, Person person, std::string driverLicenseNumber
) : Account(id, password, person) {
    this->driverLicenseNumber = std::move(driverLicenseNumber);
}

bool Customer::signContract(std::string vehicleID, VehicleInventory &inventory) {
    for (auto &reservation: userReservation) {
        if (reservation.getReservationID() == vehicleID) {
            for (auto &vehicle: inventory.getAllVehicles()) {
                if (vehicle->getLicenseNumber() == vehicleID) {
                    std::list<VehicleReservation> reservations = vehicle->getReservationsHistory();
                    reservations.push_back(reservation);
                    return true;
                }
            }
        }
    }
    return false;
}

bool Customer::returnVehicle(std::string vehicleID, VehicleInventory &inventory) {
    for (auto &vehicle: inventory.getAllVehicles()) {
        if (vehicle->getLicenseNumber() == vehicleID) {
            vehicle->returnVehicle();
            return true;
        }
    }
    return false;
}
