#include <string>
#include <fstream>
#include <sstream>
#include "csv_reader.h"

#include "../models/connection.h"
#include "../models/station.h"

std::vector<std::vector<std::string>> readCSV(std::string path) {
    std::fstream fin;

    fin.open(path, std::ios::in);

    std::vector<std::vector<std::string>> data;
    std::string line, word;
    bool first_row = true;
    for (std::string line; std::getline(fin, line); ) {
        if (first_row) {
            first_row = false;
            continue;
        }
        std::vector<std::string> row;

        std::stringstream s(line);

        while (getline(s, word, ',')) {
            row.push_back(word);
        }

        data.push_back(row);
    }

    fin.close();

    return data;
}

std::unordered_map<std::string, Station> station_parser(std::vector<std::vector<std::string>> stations) {
    std::unordered_map<std::string, Station> data;

    for (std::vector<std::string> station : stations) {
        Station station_obj;
        station_obj.id = station[0];
        station_obj.name = station[1];

        data.insert(std::make_pair(station_obj.id, station_obj));
    }

    return data;
}

std::vector<Connection> connection_parser(std::vector<std::vector<std::string>> connections) {
    std::vector<Connection> data;

    for (std::vector<std::string> connection : connections) {
        Connection connection_obj;
        connection_obj.station_a = connection[0];
        connection_obj.station_b = connection[1];
        connection_obj.duration = std::stoi(connection[2]);

        data.push_back(connection_obj);
    }

    return data;
}