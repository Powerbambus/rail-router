# rail-router
## What is this?
This is an simple dijkstra algorithm path finder for rail routes. It takes stations and connections from `.csv`-Files and calculates the shortest route from an given start and end station.
## Why does this exists?
This solves no real problem but I made it to learn a bit more about C++. I will add more stuff in future to it. I think it's a good starter project for others who want to learn more about C++.
## How to build it?
Everything needed is in the `CMakeLists.txt`. There are no external dependecies. All is coming from internal C++ libraries.
## How to use it?
Enter your desired start and end station into the CLI and get the optimal route calculated. 
## The dataformat
There are two different `.csv`. In the `stations.csv` you can put the ID and name of your stations. In the `connections.csv` you put connections between two stations and the duration for this track section in minutes.
## What's next?
- [x] CLI
- [ ] Add more stations. 
The bigger future plan is to add more functions like timetables, capacity calculator and conflict solver. Maybe sometime I add track signals and crossovers. But that's wide in the future.

