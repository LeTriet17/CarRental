//
// Created by jaylong on 1/22/22.
//
#include <string>
#ifndef CARRENTAL_DATETIME_H
#define CARRENTAL_DATETIME_H
using namespace std;

struct Date{
    int year, month, day;
    Date();
    Date(int year, int month, int day);
    string getDate();
};


#endif //CARRENTAL_DATETIME_H
