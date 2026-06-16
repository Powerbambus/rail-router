#pragma once
#include <cstdint>
#include <vector>
#include <string>

struct Route {
    std::vector<std::string> stations;
    uint16_t total_duration;
};
