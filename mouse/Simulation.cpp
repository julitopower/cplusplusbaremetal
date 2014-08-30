#include <Simulation.hpp>
#include <iostream>

Simulation::Simulation(const Map& map) : _mice(), _map(&map)
{
  std::cout << "Constructing a simulation" <<  std::endl;
  map.print();
}

Simulation::~Simulation()
{
  std::cout << "Destructing a simulation" << std::endl;
}

void Simulation::runOneStep()
{
  std::cout << "Running one step of the simulation" << std::endl;
  for(std::vector<Mouse>::iterator it = _mice.begin() ; it != _mice.end() ; ++it)
  {
    it->update();
  }
  _map->print(_mice[0].x, _mice[0].y);
}

void Simulation::runSteps(const unsigned int steps) {
  for(int i = 0 ; i < steps ; ++i)
    {
      runOneStep();
    }
}

void Simulation::addMouse(const Mouse& m) {
  std::cout << "Adding mouse " << &m << std::endl;
  _mice.push_back(m);
}

bool Simulation::canMoveFrom(const int x, const int y, const Direction dir) const {
  return _map->canMoveFrom(x, y, dir);
}
