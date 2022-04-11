//
// Created by jaylong on 1/22/22.
//

#ifndef CARRENTAL_CONSTANT_H
#define CARRENTAL_CONSTANT_H
#include <bits/stdc++.h>
enum class BillItemType {
    BASE_CHARGE = 1,
    ADDITIONAL_SERVICE = 2,
    FINE = 3,
    OTHER = 4
};
enum class VehicleLogType {
    ACCIDENT = 1,
    FUELING = 2,
    CLEANING_SERVICE = 3,
    OIL_CHANGE = 4,
    REPAIR = 5,
    OTHER = 6
};
enum class VanModel {
    PASSENGER = 1,
    CARGO = 2
};
enum class CarModel{
    ECONOMY = 1,
    COMPACT = 2,
    INTERMEDIATE = 3,
    FULL_SIZE = 4,
    PREMIUM = 5,
};
enum class MotorcycleModel {
    SEDAN = 1,
    SPORT = 2,
    CROSSOVER = 3,
    SCOOTER = 4,
};
enum class VehicleStatus{
    AVAILABLE = 1,
    LOANED= 2,
    BEING_SERVICED = 3,
};

enum class ReservationStatus{
   ACTIVE = 1,
   PENDING = 2,
   CONFIRMED = 3,
   COMPLETED = 4,
   CANCELLED = 5,
   NONE = 6
};
enum class AccountStatus{
    ACTIVE = 1,
    CLOSED = 2,
    CANCELLED = 3,
    BLACKLISTED = 4,
    BLOCKED = 5,
};
enum class PaymentStatus{
  UNPAID = 1,
  PERFORMED = 2,
  COMPLETED = 3,
  FILED = 4,
  DECLINED = 5,
  CANCELLED = 6,
  ABANDONED = 7,
  SETTLING = 8,
  SETTLED = 9,
  REFUNDED = 10
};
enum class VehicleType{
    CAR = 1,
    VAN = 2,
    MOTORCYCLE = 3,
};
struct Address{
    std::string street, city, country;
    Address();
    Address(std::string street, std::string city, std::string country);
};
struct Person{
    std::string name, email, phone;
    Address address;
    Person();
    Person(std::string name, std::string email, std::string phone, Address address);
};

#endif //CARRENTAL_CONSTANT_H
