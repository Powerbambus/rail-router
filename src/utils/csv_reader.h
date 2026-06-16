#pragma once
#include <string>
#include <unordered_map>
#include <vector>

#include "../models/station.h"
#include "../models/connection.h"

std::vector<std::vector<std::string>> readCSV(std::string path);

std::unordered_map<std::string, Station> station_parser(std::vector<std::vector<std::string>> stations);

std::vector<Connection> connection_parser(std::vector<std::vector<std::string>> connections);