#include <iostream>
#include "station.h"

void Station::print() {
    std::cout << "ID: " << this->id << std::endl;
    std::cout << "Name: " << this->name << std::endl;
}