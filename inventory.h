//
// Created by jaylong on 1/22/22.
//

#ifndef CARRENTAL_INVENTORY_H
#define CARRENTAL_INVENTORY_H
#include "vehicle.h"
#include "constant.h"
#include <list>

class Search {
public:
    virtual std::list<Vehicle*> searchByType(VehicleType type) = 0;
    virtual std::list<Vehicle*> searchByModel(VehicleType type, int model) = 0;
    virtual std::list<Vehicle*> searchByCapacity(int capacity) = 0;
};
class VehicleInventory: public Search {
    std::list<Vehicle*> availableVehicles;
    std::list<Vehicle*> totalVehicles;
    std::list<Vehicle*> addByStatus(VehicleStatus status);
    public:
    explicit VehicleInventory(std::list<Vehicle*>& vehicles);
    void serviceFleet();
    std::list<Vehicle*> searchByType(VehicleType type) override;
    std::list<Vehicle*> searchByModel(VehicleType type, int model) override;
    std::list<Vehicle*> searchByCapacity(int capacity) override;
    std::list<Vehicle*> getAvailableVehicles();
    std::list<Vehicle*> getRentedVehicles();
    std::list<Vehicle*> getAllVehicles();
};


#endif //CARRENTAL_INVENTORY_H
