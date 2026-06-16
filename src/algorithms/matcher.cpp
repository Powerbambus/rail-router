#include "matcher.h"

#include <algorithm>
#include <stdexcept>

std::unordered_map<std::string, Station> matcher(std::string input, std::unordered_map<std::string, Station> network_stations) {
    transform(input.begin(), input.end(), input.begin() ,::tolower);
    std::unordered_map<std::string, Station> output;

    for (auto& station : network_stations) {
        Station& station_obj = station.second;
        std::string station_name = station_obj.name;
        transform(station_name.begin(), station_name.end(), station_name.begin() ,::tolower);
        std::string station_id = station_obj.id;
        transform(station_id.begin(), station_id.end(), station_id.begin() ,::tolower);
        if (station_id == input || station_name == input) {
            std::unordered_map<std::string, Station> exact_output;
            exact_output.insert(std::make_pair(station_obj.id, station_obj));
            return exact_output;
        }
        if (station_id.find(input) != std::string::npos || station_name.find(input) != std::string::npos) {
            output.insert(std::make_pair(station_obj.id, station_obj));
        }
    }

    if (output.empty()) {
        throw std::invalid_argument("No stations found");
    }
    return output;
}
