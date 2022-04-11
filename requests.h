//
// Created by jaylong on 1/22/22.
//

#ifndef CARRENTAL_REQUESTS_H
#define CARRENTAL_REQUESTS_H
#include <list>
#include <iostream>
enum class Service{
    Driver = 1,
    RoadsideAssistance = 2,
};
enum class Equipment{
    AirConditioner = 1,
    GPS = 2,
    Bluetooth = 3,
    WiFi = 4
};
enum class RentalInsurance{
    PersonalInsurance = 1,
    BelongingInsurance = 2,
    LiabilityInsurance = 3
};
template<class T>
class Request{
    std::list<T> requests;
public:
    void addRequest(T request);
    void removeRequest(T request);
    std::list<T> getRequests();
};

template<class T>
void Request<T>::addRequest(T request) {
    requests.push_back(request);
}

template<class T>
void Request<T>::removeRequest(T request) {
    requests.remove(request);
}

template<class T>
std::list<T> Request<T>::getRequests() {
    return requests;
}

#endif //CARRENTAL_REQUESTS_H
