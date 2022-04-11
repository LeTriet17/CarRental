cmake_minimum_required(VERSION 3.21)
project(CarRental)

set(CMAKE_CXX_STANDARD 14)

add_executable(CarRental main.cpp constant.cpp constant.h user.cpp user.h vehicle.cpp vehicle.h datetime.cpp datetime.h requests.cpp requests.h inventory.cpp inventory.h payment.cpp payment.h vehiclereservation.cpp vehiclereservation.h)
