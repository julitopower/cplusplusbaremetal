project (Mouse-Maze)
cmake_minimum_required (VERSION 2.8)

include_directories(.)

set (lib_headers Simulation.hpp Mouse.hpp Pilot.hpp DefaultPilot.hpp Map.hpp)
set (lib_sources Simulation.cpp Mouse.cpp Map.cpp DefaultPilot.cpp)
add_library (mazesimulation ${lib_sources} ${lib_headers})

set (headers )
set (sources main.cpp)
add_executable (mousemaze ${sources})
target_link_libraries(mousemaze mazesimulation)
