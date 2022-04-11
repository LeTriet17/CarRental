//
// Created by jaylong on 1/31/22.
//

#ifndef CARRENTAL_VEHICLERESERVATION_H
#define CARRENTAL_VEHICLERESERVATION_H

#include "datetime.h"
#include  "constant.h"

class VehicleReservation {
    std::string reservationID;
    Date creationDate;
    Date endDate;
    std::string pickupLocation;
    std::string returnLocation;
public:
    VehicleReservation(std::string reservationID, Date creationDate, Date endDate, std::string pickupLocation, std::string returnLocation);
    std::string getReservationID();
    VehicleReservation fetchDetails();
};


#endif //CARRENTAL_VEHICLERESERVATION_H
