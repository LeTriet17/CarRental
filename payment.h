//
// Created by jaylong on 1/23/22.
//

#ifndef CARRENTAL_PAYMENT_H
#define CARRENTAL_PAYMENT_H

#include "datetime.h"
#include "constant.h"
#include <iostream>

class Payment {
    Date creationDate;
    double amount;
    PaymentStatus status;
public:
    bool initiateTransaction();
};

class CreditCardPayment : public Payment {
    std::string nameOnCard;
};

class CashPayment : public Payment {
    double cashTendered;
};

#endif //CARRENTAL_PAYMENT_H
