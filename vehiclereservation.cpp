//
// Created by jaylong on 1/31/22.
//

#include "vehiclereservation.h"

#include <utility>

VehicleReservation::VehicleReservation(std::string reservationID, Date creationDate, Date endDate,
                                       std::string pickupLocation, std::string returnLocation) {
    this->reservationID = std::move(reservationID);
    this->creationDate = creationDate;
    this->endDate = endDate;
    this->pickupLocation = std::move(pickupLocation);
    this->returnLocation = std::move(returnLocation);

}

VehicleReservation VehicleReservation::fetchDetails() {
   return *this;
}

std::string VehicleReservation::getReservationID() {
    return reservationID;
}
