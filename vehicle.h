//
// Created by jaylong on 1/22/22.
//

#ifndef CARRENTAL_VEHICLE_H
#define CARRENTAL_VEHICLE_H
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include "constant.h"
#include "requests.h"
#include "datetime.h"
#include "vehiclereservation.h"
using namespace rapidjson;

class History {
    class HistoryNode {
    public:
        int mileage;
        Date date;
        std::string location;
        HistoryNode(int mileage, Date date, std::string location) : mileage(mileage), date(date), location(location) {}
        int getMileage() const { return mileage; }
    };

    std::list<HistoryNode> engines;
    std::list<HistoryNode> transmissions;
    std::list<HistoryNode> tires;
public:
    void addEngineService(int mileage, Date date, std::string location);
    void addTransmissionService(int mileage, Date date, std::string location);
    void addTireService(int mileage, Date date, std::string location);
    int lastEngineMileage();
    int lastTransmissionMileage();
    int lastTireMileage();
    void printJson();
};


class Vehicle {
    std::string licenseNumber;
    int passengerCapacity;
    VehicleStatus status;
    int mileage;
    std::list<Service> services;
    std::list<Equipment> equipments;
    std::list<RentalInsurance> rentalInsurances;
    std::list<VehicleReservation> reservations;

    std::list<Service> getServices();

    std::list<Equipment> getEquipments();

    std::list<RentalInsurance> getRentalInsurances();

public:
    History history;

    Vehicle(std::string licenseNumber, int passengerCapacity,
            VehicleStatus status, int mileage);
    bool reserveVehicle();

    bool pickUpVehicle();

    bool returnVehicle();

    std::string getLicenseNumber();
    int getMileage();
    VehicleStatus getStatus();
    std::list<VehicleReservation> getReservationsHistory();
    virtual VehicleType getType() = 0;

    virtual int getModel() = 0;
    virtual std::string getVehicleModel() = 0;
    int getCapacity() const;
    virtual bool serviceEngine() = 0;
    virtual bool serviceTransmission() = 0;
    virtual bool serviceTires() = 0;
};

class Car : public Vehicle {
    VehicleType type = VehicleType::CAR;
    CarModel model;
public:
    Car(std::string licenseNumber, int passengerCapacity,
        VehicleStatus status, CarModel model, int mileage);

    VehicleType getType() override;

    int getModel() override;
    std::string getVehicleModel() override;
    bool serviceEngine() override;
    bool serviceTransmission() override;
    bool serviceTires() override;
};

class Van : public Vehicle {
    VehicleType type = VehicleType::VAN;
    VanModel model;
public:
    Van(std::string licenseNumber, int passengerCapacity,
        VehicleStatus status, VanModel model, int mileage);

    VehicleType getType() override;

    int getModel() override;
    std::string getVehicleModel() override;
    bool serviceEngine() override;
    bool serviceTransmission() override;
    bool serviceTires() override;
};
class Motorcycle : public Vehicle {
    VehicleType type = VehicleType::MOTORCYCLE;
    MotorcycleModel model;
public:
    Motorcycle(std::string licenseNumber, int passengerCapacity,
            VehicleStatus status, MotorcycleModel model, int mileage);

    VehicleType getType() override;

    int getModel() override;
    std::string getVehicleModel() override;
    bool serviceEngine() override;
    bool serviceTransmission() override;
    bool serviceTires() override;
};
static std::ostream& operator<<(std::ostream& os, const VehicleType& Type) {
    switch (Type) {
        case VehicleType::CAR:
            os << "CAR";
            break;
        case VehicleType::VAN:
            os << "VAN";
            break;
        case VehicleType::MOTORCYCLE:
            os << "MOTORCYCLE";
            break;
    }
    return os;
}

static std::ostream& operator<<(std::ostream& os, const Service& ser);
static std::ostream& operator<<(std::ostream& os, const Equipment& eq);
static std::ostream& operator<<(std::ostream& os, const RentalInsurance& rentalInsurance);
#endif //CARRENTAL_VEHICLE_H
