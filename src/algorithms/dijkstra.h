#pragma once
#include "../models/connection.h"
#include "../models/route.h"
#include "../models/station.h"

Route find_shortest_path_dijkstra(
    std::string start_station,
    std::string end_station,
    std::vector<Connection> connections,
    std::unordered_map<std::string, Station> stations,
    bool verbose
    );
