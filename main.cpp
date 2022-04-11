#include <iostream>
#include "vehicle.h"
#include "constant.h"
#include "inventory.h"
#include "user.h"

int main() {

    // Initialize the inventory
    Vehicle *car1 = new Car("0001", 5, VehicleStatus::AVAILABLE, CarModel::ECONOMY, 1000);
    Vehicle *car2 = new Car("0002", 4, VehicleStatus::BEING_SERVICED, CarModel::INTERMEDIATE, 1005);
    Vehicle *car3 = new Car("0003", 3, VehicleStatus::AVAILABLE, CarModel::PREMIUM, 1010);
    Vehicle *van1 = new Van("0004", 2, VehicleStatus::AVAILABLE, VanModel::PASSENGER, 2000);
    Vehicle *van2 = new Van("0005", 6, VehicleStatus::AVAILABLE, VanModel::CARGO, 2005);
    Vehicle *van3 = new Van("0006", 6, VehicleStatus::AVAILABLE, VanModel::CARGO, 3005);
    Vehicle *motocycle1 = new Motorcycle("0007", 1, VehicleStatus::AVAILABLE, MotorcycleModel::SPORT, 3000);
    Vehicle *motocycle2 = new Motorcycle("0008", 1, VehicleStatus::AVAILABLE, MotorcycleModel::SEDAN, 3005);
    Vehicle *motocycle3 = new Motorcycle("0009", 1, VehicleStatus::AVAILABLE, MotorcycleModel::CROSSOVER, 3010);
    Vehicle *car4 = new Car("0010", 4, VehicleStatus::BEING_SERVICED, CarModel::PREMIUM, 1505);

    std::list<Vehicle *> vehicles = {car1, car2, car3,car4, van1, van2, van3,motocycle1, motocycle2, motocycle3};
    VehicleInventory inventory(vehicles);

    Person user1("JayLong", "triet.lecsk20@hcmut.edu.vn", "123456789", Address("Ly Thuong Kiet", "HCMC", "Vietnam"));
    Customer cus1(1, "JayLong", user1, "00002");
    int choice;
    while (true) {
        std::cout << "1. Get reservation <0 to quit>" << std::endl;
        std::cout << "2. Vehicles maintenance <0 to quit>" << std::endl;
        std::cout << "3. Return vehicle <0 to quit>" << std::endl;
        try {
            std::cin >> choice;
            if (choice == 1) {
                std::cout << "1. Book a vehicle: " << std::endl;
                std::cout << "2. Sign a contract: " << std::endl;
                try {
                    std::cin >> choice;
                    if (choice == 1)
                        cus1.getReservations(inventory);
                    else if (choice == 2) {
                        std::cout << "Enter the vehicle ID: ";
                        std::string vehicleID;
                        std::cin >> vehicleID;
                        if (!cus1.signContract(vehicleID, inventory)) {
                            throw std::invalid_argument("Invalid vehicle ID or this vehicle is not booked before");
                        }
                    } else
                        throw std::invalid_argument("Invalid choice");
                }
                catch (char const *e) {
                    std::cout << e << std::endl;
                    continue;
                }
            } else if (choice == 2) {
                inventory.serviceFleet();
            } else if (choice == 3) {
                std::cout << "Enter the vehicle ID: ";
                std::string vehicleID;
                std::cin >> vehicleID;
                if (!cus1.returnVehicle(vehicleID, inventory)) {
                    throw std::invalid_argument("Invalid vehicle ID or this vehicle is not booked or rented before");
                }
            } else if (choice == 0) break;
            else {
                throw std::invalid_argument("Invalid choice");
            }
        } catch (std::invalid_argument &e) {
            std::cout << e.what() << std::endl;
        }
        catch (const char *msg) {
            std::cout << msg << std::endl;
            std::cout << "Enter new choice <q to quit>" << std::endl;
            continue;
        }

    }
    return 0;
}
