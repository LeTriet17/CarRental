//
// Created by jaylong on 1/22/22.
//
//These classes are used to represent different types of users interacting with the system.
#ifndef CARRENTAL_USER_H
#define CARRENTAL_USER_H

#include "constant.h"
#include "vehicle.h"
#include "datetime.h"
#include "inventory.h"
#include "vehiclereservation.h"
#include <list>

class Account {
    int id;
    std::string password;
    Person person;

    void printAvailableVehicles(std::list<Vehicle*> &);

public:
    Account(int id, std::string password, Person person);

    void showInventory(VehicleInventory &inventory);

    void showRentedVehicles(VehicleInventory &inventory);

    void searchInventoryByType(VehicleInventory &inventory, VehicleType type);

    void searchInventoryByModel(VehicleInventory &inventory, VehicleType type, int model);

    void searchInventoryByCapacity(VehicleInventory &inventory, int capacity);

    void createAccount(std::string password, Person person);

    void UpdateAccount(std::string password, Person person);

    void getAvailableVehicles(VehicleInventory &inventory);

    bool resetPassword(std::string newPassword);

};

class Customer : public Account {
    std::string driverLicenseNumber;
    Date driverLicenseExpirationDate;
    std::list<VehicleReservation> userReservation;
public:
    Customer(int id, std::string password, Person person, std::string driverLicenseNumber);

    std::list<VehicleReservation> getReservations(VehicleInventory &inventory);
    bool signContract(std::string vehicleID,VehicleInventory&inventory);
    bool returnVehicle(std::string vehicleID,VehicleInventory&inventory);
};

#endif //CARRENTAL_USER_H
