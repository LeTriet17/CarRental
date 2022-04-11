//
// Created by jaylong on 1/22/22.
//

#include "datetime.h"
Date::Date(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}

Date::Date() {
    this->year = 0;
    this->month = 0;
    this->day = 0;
}
string Date::getDate() {
    string date = to_string(day); + "-" + to_string(month) + "-" + to_string(year);
    return date;
}
