#include <iostream>
#include <ostream>

#include "./utils/csv_reader.h"
#include "algorithms/dijkstra.h"

std::string stations_path = "../data/stations.csv";
std::string connections_path = "../data/connections.csv";

int main() {
    const std::vector<std::vector<std::string>> stations_csv = readCSV(stations_path);
    std::unordered_map<std::string, Station> stations = station_parser(stations_csv);

    const std::vector<std::vector<std::string>> connections_csv = readCSV(connections_path);
    std::vector<Connection> connections = connection_parser(connections_csv);

    std::string start_station = "EWIC";
    std::string end_station = "EDO";
    std::cout << "Searching route from " << start_station << " to " << end_station << std::endl;
    std::cout << "Start searching..." << std::endl;
    Route route = find_shortest_path_dijkstra(start_station, end_station, connections, stations);
    std::cout << std::endl;
    std::cout << "Found route with a total duration of " << route.total_duration << " min." << std::endl;
    std::cout << start_station << " -> ";
    for (auto& station : route.stations) {
        if (station == start_station || station == end_station) continue;
        std::cout << station <<  " -> ";
    }
    std::cout << end_station;

    return 0;
}