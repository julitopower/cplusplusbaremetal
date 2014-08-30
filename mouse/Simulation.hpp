#ifndef SIMULATION
#define SIMULATION

#include <Map.hpp>
#include <Mouse.hpp>
#include <vector>

/*
  The simulation plays the role of a controller:

  It owns a map and a list of mice that are wandering around the map.
  We can simulate individual steps of the simulation. Since the simulation
  owns the map, when a Mouse wants to execute a movement, it asks the
  simulation whether that movement is possible or not.
*/
class Simulation
{
public:

  Simulation(const Map& map);
  ~Simulation();
  void runOneStep();
  void runSteps(const unsigned int steps);
  void addMouse(const Mouse& m);
  void setMap(const std::vector<char>& m);
  bool canMoveFrom(const int x, const int y, const Direction dir) const;
private:
  std::vector<Mouse> _mice;
  const Map* _map;
};

#endif
