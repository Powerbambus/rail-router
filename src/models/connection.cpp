#include <iostream>

#include "connection.h"

void Connection::print() {
    std::cout << this->station_a << " -- " << this->duration << " Min. -> " << this->station_b << std::endl;
}