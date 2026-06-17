#include <iostream>
#include <ostream>
#include <algorithm>

#include "./utils/csv_reader.h"
#include "algorithms/dijkstra.h"
#include "algorithms/matcher.h"

std::string stations_path = "../data/stations.csv";
std::string connections_path = "../data/connections.csv";

int main() {
    const std::vector<std::vector<std::string>> stations_csv = readCSV(stations_path);
    std::unordered_map<std::string, Station> stations = station_parser(stations_csv);

    const std::vector<std::vector<std::string>> connections_csv = readCSV(connections_path);
    std::vector<Connection> connections = connection_parser(connections_csv);

    bool running = true;
    while (running) {
        std::string start_station;
        std::string end_station;
        bool start_station_input = false;
        while (!start_station_input) {
            std::string start_input;
            std::cout << "Input start station: ";
            std::cin >> start_input;
            try {
                std::unordered_map<std::string, Station> start_stations = matcher(start_input, stations);
                if (start_stations.size() == 1) {
                    start_station = start_stations.begin()->first;
                    start_station_input = true;
                }
                if (start_stations.size() > 1) {
                    std::cout << "Multiple stations found: " << start_stations.size() << std::endl;
                    for (auto& station : start_stations) {
                        std::cout << station.second.id << " - " << station.second.name << std::endl;
                    }
                    std::cout << "Please select a station!" << std::endl;
                    continue;
                }
            } catch (std::invalid_argument& e) {
                std::cout << "Invalid input! Please try again!" << std::endl;
                continue;
            }
        }
        bool end_station_input = false;
        while (!end_station_input) {
            std::string end_input;
            std::cout << "Input end station: ";
            std::cin >> end_input;
            try {
                std::unordered_map<std::string, Station> end_stations = matcher(end_input, stations);
                if (end_stations.size() == 1) {
                    end_station = end_stations.begin()->first;
                    end_station_input = true;
                }
                if (end_stations.size() > 1) {
                    std::cout << "Multiple stations found: " << end_stations.size() << std::endl;
                    for (auto& station : end_stations) {
                        std::cout << station.second.id << " - " << station.second.name << std::endl;
                    }
                    std::cout << "Please select a station!" << std::endl;
                    continue;
                }
            } catch (std::invalid_argument& e) {
                std::cout << "Invalid input! Please try again!" << std::endl;
                continue;
            }
        }
        std::cout << "Searching route from " << stations[start_station].name << " to " << stations[end_station].name << std::endl;
        bool simulation_output = false;
        bool simulation_input = false;
        while (!simulation_input) {
            std::string simulation_input_string;
            std::cout << "Do you want an simulation output? y/n" << std::endl;
            std::cin >> simulation_input_string;
            transform(simulation_input_string.begin(), simulation_input_string.end(), simulation_input_string.begin() ,::tolower);
            if (simulation_input_string == "y") {
                simulation_output = true;
                simulation_input = true;
                break;
            } else if (simulation_input_string == "n") {
                simulation_output = false;
                simulation_input = true;
                break;
            } else {
                std::cout << "Invalid input! Please try again!" << std::endl;
            }
        }
        std::cout << "Start searching..." << std::endl;
        Route route = find_shortest_path_dijkstra(start_station, end_station, connections, stations, simulation_output);
        std::cout << std::endl;
        std::cout << "Found route with a total duration of " << route.total_duration << " min." << std::endl;
        std::cout << stations[start_station].name << " -> ";
        for (auto& station : route.stations) {
            if (station == start_station || station == end_station) continue;
            std::cout << stations[station].name <<  " -> ";
        }
        std::cout << stations[end_station].name;
        std::cout << std::endl;
        std::cout << "Press q to exit or Enter to continue...";
        std::string exit;
        std::cin.ignore();
        std::getline(std::cin, exit);
        if (exit == "q") {
            running = false;
            std::cout << "Thanks for using the rail router" << std::endl;
        }
    }
    return 0;
}