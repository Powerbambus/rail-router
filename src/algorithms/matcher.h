#pragma once
#include <unordered_map>
#include <string>

#include "../models/station.h"

std::unordered_map<std::string, Station> matcher(std::string input, std::unordered_map<std::string, Station> network_stations);