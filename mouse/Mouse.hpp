#ifndef MOUSE
#define MOUSE

#include <Map.hpp>
#include <Pilot.hpp>

class Simulation;

class Mouse
{
public:
  Mouse(const Simulation& simulation);
  Mouse(const Mouse& that);
  Mouse& operator=(const Mouse& that);
  ~Mouse();
  unsigned int x;
  unsigned int y;
  void update();
  bool move(Direction direction);
  
private:
  const Simulation* _simulation;
  Pilot * _pilot;
};

#endif
