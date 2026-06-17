#include <iostream>

#include "connection.h"

void Connection::print() {
    std::cout << this->station_a << " -- " << this->duration << " min. -> " << this->station_b << std::endl;
}