#include <unordered_map>
#include <algorithm>
#include <map>
#include <queue>


#include "dijkstra.h"

#include <limits.h>
#include <stdexcept>

#include "../models/station.h"

Route find_shortest_path_dijkstra(std::string start_station, std::string end_station, std::vector<Connection> connections, std::unordered_map<std::string, Station> network_stations) {
    if (network_stations.find(start_station) == network_stations.end()) {
        throw std::logic_error("start station not found");
    }
    if (network_stations.find(end_station) == network_stations.end()) {
        throw std::logic_error("end station not found");
    }
    std::unordered_map<std::string, uint16_t> costs;
    std::vector<std::string> visited_stations;
    std::unordered_map<std::string, std::string> came_from;
    std::priority_queue<std::pair<uint16_t, std::string>> queue;

    costs[start_station] = 0;
    queue.push(std::make_pair(0, start_station));

    bool found = false;
    while (!found) {
        std::pair<uint16_t, std::string> current = queue.top();
        queue.pop();
        if (current.second == end_station) {
            found = true;
            break;
        }
        if (std::find(visited_stations.begin(), visited_stations.end(), current.second) != visited_stations.end()) {
            continue;
        }

        visited_stations.push_back(current.second);
        for (auto& connection : connections) {
            if (connection.station_a == current.second) {
                if (!costs[connection.station_b]) {
                    costs[connection.station_b] = INT_MAX;
                }
                if (costs[current.second] + connection.duration < costs[connection.station_b]) {
                    costs[connection.station_b] = costs[current.second] + connection.duration;
                    queue.push(std::make_pair(connection.duration, connection.station_b));
                    came_from[connection.station_b] = current.second;
                }
            } else if (connection.station_b == current.second) {
                if (!costs[connection.station_a]) {
                    costs[connection.station_a] = INT_MAX;
                }
                if (costs[current.second] + connection.duration < costs[connection.station_a]) {
                    costs[connection.station_a] = costs[current.second] + connection.duration;
                    queue.push(std::make_pair(connection.duration, connection.station_a));
                    came_from[connection.station_a] = current.second;
                }
            }
        }
        if (queue.empty()) {
            throw std::logic_error("can't find connection between start and end station");
        }
    }

    std::vector<std::string> stations;
    std::string current_station = end_station;
    while (current_station != start_station) {
        stations.push_back(current_station);
        current_station = came_from[current_station];
    }
    stations.push_back(start_station);
    std::reverse(stations.begin(), stations.end());
    Route route;
    route.stations = stations;
    route.total_duration = costs[end_station];

    return route;
}
