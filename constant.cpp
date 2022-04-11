//
// Created by jaylong on 1/22/22.
//

#include "constant.h"

#include <utility>
Address::Address(std::string street, std::string city,  std::string country) {
    this->street = std::move(street);
    this->city = std::move(city);
    this->country = std::move(country);
}

Address::Address() {
    this->street = "";
    this->city = "";
    this->country = "";
}


Person::Person(std::string name, std::string email, std::string phone, Address address) {
    this->name = std::move(name);
    this->email = std::move(email);
    this->phone = std::move(phone);
    this->address = std::move(address);
}

Person::Person() {
    this->name = "";
    this->email = "";
    this->phone = "";
    this->address = Address();
}


