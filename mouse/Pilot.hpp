#ifndef PILOT
#define PILOT

#include <Map.hpp>
#include <iostream>

class Mouse;

class Pilot
{
public:
  Pilot(Mouse& mouse) : _mouse(&mouse)
  {
    //std::cout << "Creating base pilot for mouse" << &mouse  << std::endl;
  };
  virtual ~Pilot() {};
  virtual char nextMove() = 0;
protected:
  Mouse* _mouse;
};

static Direction comesFrom(Direction previousMove)
{
  switch (previousMove) {
  case right : return left;
  case left : return right;
  case down: return up;
  case up: return down;
  defaul: return none;
  }
}
  
#endif
