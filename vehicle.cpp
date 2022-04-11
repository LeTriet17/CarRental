//
// Created by jaylong on 1/22/22.
//

#include "vehicle.h"

#include <utility>
#include <vector>

static std::ostream &operator<<(std::ostream &os, const Service &ser) {
    switch (ser) {
        case Service::Driver:
            os << "Driver";
            break;

        case Service::RoadsideAssistance:
            os << "Roadside Assistance";
            break;
    }
    return os;
}

static std::ostream &operator<<(std::ostream &os, const Equipment &eq) {
    switch (eq) {
        case Equipment::AirConditioner:
            os << "Air Conditioner";
            break;
        case Equipment::GPS:
            os << "GPS";
            break;
        case Equipment::Bluetooth:
            os << "Bluetooth";
            break;
        case Equipment::WiFi:
            os << "WiFi";
            break;
    }
    return os;
}

static std::ostream &operator<<(std::ostream &os, const RentalInsurance &rentalInsurance) {
    switch (rentalInsurance) {
        case RentalInsurance::PersonalInsurance:
            os << "Personal Insurance";
            break;
        case RentalInsurance::BelongingInsurance:
            os << "Belonging Insurance";
            break;
        case RentalInsurance::LiabilityInsurance:
            os << "Liability Insurance";
            break;
    }
    return os;
}

Vehicle::Vehicle(std::string licenseNumber, int passengerCapacity,
                 VehicleStatus status, int mileage) {
    this->licenseNumber = std::move(licenseNumber);
    this->passengerCapacity = passengerCapacity;
    this->status = status;
    this->mileage = mileage;
}

bool Vehicle::reserveVehicle() {
    this->status = VehicleStatus::LOANED;
    std::cout << "Vehicle " << this->licenseNumber << " is now reserved." << std::endl;
    this->equipments = getEquipments();
    this->services = getServices();
    this->rentalInsurances = getRentalInsurances();
    return true;
}

bool Vehicle::pickUpVehicle() {
    this->status = VehicleStatus::BEING_SERVICED;
    return true;
}

bool Vehicle::returnVehicle() {
    this->status = VehicleStatus::AVAILABLE;
    return true;
}

VehicleStatus Vehicle::getStatus() {
    return this->status;
}

std::list<Service> Vehicle::getServices() {
    int i = 1;
    std::vector<Service> servs = {Service::Driver, Service::RoadsideAssistance};
    for (Service serv: servs) {
        std::cout << i << ". " << serv << std::endl;
        i++;
    }
    std::list<Service> res;
    while (true) {
        std::cout << "Enter equipment number to reserve (press 0 to cancel): ";
        int equipmentNumber;
        std::cin >> equipmentNumber;
        if (equipmentNumber == 0) {
            std::cout << "Customer Services cancelled." << std::endl;
            break;
        } else if (equipmentNumber < 0 || equipmentNumber > servs.size()) {
            std::cout << "Invalid equipment number. Try again." << std::endl;
            continue;
        }

        res.push_back(servs.at(equipmentNumber - 1));
    }
    return res;
}

std::list<Equipment> Vehicle::getEquipments() {
    int i = 1;
    std::vector<Equipment> equips = {Equipment::WiFi, Equipment::GPS, Equipment::Bluetooth, Equipment::AirConditioner};
    for (auto &equipment: equips) {
        std::cout << i++ << ". " << equipment << std::endl;
    }
    std::list<Equipment> res;
    while (true) {
        std::cout << "Enter equipment number to reserve (press 0 to cancel): ";
        int equipmentNumber;
        std::cin >> equipmentNumber;
        if (equipmentNumber == 0) {
            std::cout << "Customer Equipment cancelled." << std::endl;
            break;
        } else if (equipmentNumber < 0 || equipmentNumber > equips.size()) {
            std::cout << "Invalid equipment number. Try again." << std::endl;
            continue;
        }

        res.push_back(equips.at(equipmentNumber - 1));
    }
    return res;
}

std::list<RentalInsurance> Vehicle::getRentalInsurances() {
    int i = 1;
    std::vector<RentalInsurance> insurances = {RentalInsurance::PersonalInsurance, RentalInsurance::BelongingInsurance,
                                               RentalInsurance::LiabilityInsurance};
    for (auto insurance: insurances) {
        std::cout << i++ << ". " << insurance << std::endl;
    }
    std::list<RentalInsurance> res;
    while (true) {
        std::cout << "Enter insurance number to reserve (press 0 to cancel): ";
        int insuranceNumber;
        std::cin >> insuranceNumber;
        if (insuranceNumber == 0) {
            std::cout << "Customer Rental Insurances cancelled." << std::endl;
            break;
        } else if (insuranceNumber < 0 || insuranceNumber > insurances.size()) {
            std::cout << "Invalid insurance number. Try again." << std::endl;
            continue;
        }

        res.push_back(insurances.at(insuranceNumber - 1));
    }
    return res;
}


int Vehicle::getCapacity() const {
    return this->passengerCapacity;
}

std::string Vehicle::getLicenseNumber() {
    return this->licenseNumber;
}

int Vehicle::getMileage() {
    return this->mileage;
}

std::list<VehicleReservation> Vehicle::getReservationsHistory() {
    return this->reservations;
}


Car::Car(std::string licenseNumber, int passengerCapacity,
         VehicleStatus status, CarModel model, int mileage) : Vehicle(std::move(licenseNumber),
                                                                      passengerCapacity,
                                                                      status,
                                                                      mileage) {
    this->model = model;
}

VehicleType Car::getType() { return VehicleType::CAR; }

int Car::getModel() { return static_cast<int>(this->model); }

std::string Car::getVehicleModel() {
    switch (this->model) {
        case CarModel::ECONOMY:
            return "Economy";
            break;
        case CarModel::COMPACT:
            return "Compact";
            break;
        case CarModel::INTERMEDIATE:
            return "Intermediate";
            break;
        case CarModel::FULL_SIZE:
            return "Full Size";
            break;
        case CarModel::PREMIUM:
            return "Premium";
            break;
    }
}

bool Car::serviceEngine() {
    if (this->getMileage() - history.lastEngineMileage() > 1000) {
        std::cout << "Start engine service for vehicle id: " << this->getLicenseNumber() << std::endl;
        std::cout << "Enter day of service: ";
        int day;
        std::cin >> day;
        std::cout << "Enter month of service: ";
        int month;
        std::cin >> month;
        std::cout << "Enter year of service: ";
        int year;
        std::cin >> year;
        std::cout << "Enter location: ";
        std::string location;
        std::cin >> location;
        history.addEngineService(this->getMileage(), Date(year, month, day), location);
        return true;
    }
    return false;
}

bool Car::serviceTransmission() {
    if (this->getMileage() - history.lastTransmissionMileage() > 1500) {
        std::cout << "Start transmission service for vehicle id: " << this->getLicenseNumber() << std::endl;
        std::cout << "Enter day of service: ";
        int day;
        std::cin >> day;
        std::cout << "Enter month of service: ";
        int month;
        std::cin >> month;
        std::cout << "Enter year of service: ";
        int year;
        std::cin >> year;
        std::cout << "Enter location: ";
        std::string location;
        std::cin >> location;
        history.addTransmissionService(this->getMileage(), Date(year, month, day), location);
        return true;
    }
    return false;
}

bool Car::serviceTires() {
    if (this->getMileage() - history.lastTireMileage() > 2000) {
        std::cout << "Start tires service for vehicle id: " << this->getLicenseNumber() << std::endl;
        std::cout << "Enter day of service: ";
        int day;
        std::cin >> day;
        std::cout << "Enter month of service: ";
        int month;
        std::cin >> month;
        std::cout << "Enter year of service: ";
        int year;
        std::cin >> year;
        std::cout << "Enter location: ";
        std::string location;
        std::cin >> location;
        history.addTireService(this->getMileage(), Date(year, month, day), location);
        return true;
    }
    return false;
}

Van::Van(std::string licenseNumber, int passengerCapacity,
         VehicleStatus status, VanModel model, int mileage) : Vehicle(std::move(licenseNumber),
                                                                      passengerCapacity,
                                                                      status,
                                                                      mileage) {
    this->model = model;
}

VehicleType Van::getType() { return VehicleType::VAN; }

int Van::getModel() { return static_cast<int>(this->model); }

std::string Van::getVehicleModel() {
    switch (this->model) {
        case VanModel::PASSENGER:
            return "Passenger";
            break;
        case VanModel::CARGO:
            return "Cargo";
            break;
        default:
            return "";
            break;
    }
}

bool Van::serviceEngine() {
    if (this->getMileage() - history.lastEngineMileage() > 2000) {
        std::cout << "Start engine service for vehicle id: " << this->getLicenseNumber() << std::endl;
        std::cout << "Enter day of service: ";
        int day;
        std::cin >> day;
        std::cout << "Enter month of service: ";
        int month;
        std::cin >> month;
        std::cout << "Enter year of service: ";
        int year;
        std::cin >> year;
        std::cout << "Enter location: ";
        std::string location;
        std::cin >> location;
        history.addEngineService(this->getMileage(), Date(year, month, day), location);
        return true;
    }
    return false;
}

bool Van::serviceTransmission() {
    if (this->getMileage() - history.lastTransmissionMileage() > 3000) {
        std::cout << "Start transmission service for vehicle id: " << this->getLicenseNumber() << std::endl;
        std::cout << "Enter day of service: ";
        int day;
        std::cin >> day;
        std::cout << "Enter month of service: ";
        int month;
        std::cin >> month;
        std::cout << "Enter year of service: ";
        int year;
        std::cin >> year;
        std::cout << "Enter location: ";
        std::string location;
        std::cin >> location;
        history.addTransmissionService(this->getMileage(), Date(year, month, day), location);
        return true;
    }
    return false;
}

bool Van::serviceTires() {
    if (this->getMileage() - history.lastTireMileage() > 4000) {
        std::cout << "Start tires service for vehicle id: " << this->getLicenseNumber() << std::endl;
        std::cout << "Enter day of service: ";
        int day;
        std::cin >> day;
        std::cout << "Enter month of service: ";
        int month;
        std::cin >> month;
        std::cout << "Enter year of service: ";
        int year;
        std::cin >> year;
        std::cout << "Enter location: ";
        std::string location;
        std::cin >> location;
        history.addTireService(this->getMileage(), Date(year, month, day), location);
        return true;
    }
    return false;
}

void History::addEngineService(int mileage, Date date, std::string location) {
    this->engines.emplace_back(mileage, date, location);
    this->printJson();
}

void History::addTransmissionService(int mileage, Date date, std::string location) {
    this->transmissions.emplace_back(mileage, date, location);
}

void History::addTireService(int mileage, Date date, std::string location) {
    this->tires.emplace_back(mileage, date, location);
}

int History::lastEngineMileage() {
    return !engines.empty() ? engines.back().getMileage() : 0;
}

int History::lastTransmissionMileage() {
    return !transmissions.empty() ? transmissions.back().getMileage() : 0;
}

int History::lastTireMileage() {
    return !tires.empty() ? tires.back().getMileage() : 0;
}


Motorcycle::Motorcycle(std::string licenseNumber, int passengerCapacity, VehicleStatus status, MotorcycleModel model,
                       int mileage) : Vehicle(std::move(licenseNumber),
                                              passengerCapacity,
                                              status,
                                              mileage) {
    this->model = model;
}

VehicleType Motorcycle::getType() {
    return VehicleType::MOTORCYCLE;
}

int Motorcycle::getModel() {
    return static_cast<int>(this->model);
}

std::string Motorcycle::getVehicleModel() {
    switch (this->model) {
        case MotorcycleModel::SEDAN:
            return "Sedan";
            break;
        case MotorcycleModel::SPORT:
            return "Sport";
            break;
        case MotorcycleModel::CROSSOVER:
            return "Crossover";
            break;
        default:
            return "";
    }
}
bool Motorcycle::serviceEngine() {
    if (this->getMileage() - history.lastEngineMileage() > 500) {
        std::cout << "Start engine service for vehicle id: " << this->getLicenseNumber() << std::endl;
        std::cout << "Enter day of service: ";
        int day;
        std::cin >> day;
        std::cout << "Enter month of service: ";
        int month;
        std::cin >> month;
        std::cout << "Enter year of service: ";
        int year;
        std::cin >> year;
        std::cout << "Enter location: ";
        std::string location;
        std::cin >> location;
        history.addEngineService(this->getMileage(), Date(year, month, day), location);
        return true;
    }
    return false;
}

bool Motorcycle::serviceTransmission() {
    if (this->getMileage() - history.lastTransmissionMileage() > 700) {
        std::cout << "Start transmission service for vehicle id: " << this->getLicenseNumber() << std::endl;
        std::cout << "Enter day of service: ";
        int day;
        std::cin >> day;
        std::cout << "Enter month of service: ";
        int month;
        std::cin >> month;
        std::cout << "Enter year of service: ";
        int year;
        std::cin >> year;
        std::cout << "Enter location: ";
        std::string location;
        std::cin >> location;
        history.addTransmissionService(this->getMileage(), Date(year, month, day), location);
        return true;
    }
    return false;
}

bool Motorcycle::serviceTires() {
    if (this->getMileage() - history.lastTireMileage() > 900) {
        std::cout << "Start tires service for vehicle id: " << this->getLicenseNumber() << std::endl;
        std::cout << "Enter day of service: ";
        int day;
        std::cin >> day;
        std::cout << "Enter month of service: ";
        int month;
        std::cin >> month;
        std::cout << "Enter year of service: ";
        int year;
        std::cin >> year;
        std::cout << "Enter location: ";
        std::string location;
        std::cin >> location;
        history.addTireService(this->getMileage(), Date(year, month, day), location);
        return true;
    }
    return false;
}
void History::printJson() {
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    writer.StartObject();
    writer.Key("Engine");
    writer.StartArray();
    for (auto& engine : engines) 
    {
        writer.Key("Milage");
        writer.Int(engine.getMileage());
        writer.Key("Date");
        writer.String(engine.date.getDate().c_str());
        writer.Key("Location");
        writer.String(engine.location.c_str());
    }
    writer.StartObject();
    writer.EndObject();

}