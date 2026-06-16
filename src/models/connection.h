#pragma once
#include <string>
#include <cstdint>

struct Connection {
    std::string station_a;
    std::string station_b;
    uint16_t duration;

    void print();
};