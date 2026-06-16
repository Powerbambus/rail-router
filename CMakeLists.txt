cmake_minimum_required(VERSION 4.1)
project(rail_router)

set(CMAKE_CXX_STANDARD 20)

add_executable(rail_router src/main.cpp
        src/models/station.h
        src/models/connection.h
        src/models/station.cpp
        src/models/connection.cpp
        src/utils/csv_reader.cpp
        src/utils/csv_reader.h
        src/algorithms/dijkstra.cpp
        src/algorithms/dijkstra.h
        src/models/route.cpp
        src/models/route.h
        src/algorithms/matcher.cpp
        src/algorithms/matcher.h)
