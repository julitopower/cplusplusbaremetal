#include <Mouse.hpp>
#include <Simulation.hpp>
#include <DefaultPilot.hpp>
#include <iostream>

Mouse::Mouse(const Simulation& simulation)
  : _simulation(&simulation), x(0), y(0)
{
  //std::cout << "Creating new Mouse " << this << std::endl;
  _pilot = new DefaultPilot(*this);
  std::cout << "Mouse " << this << " Pilot is " << _pilot << std::endl;
}

Mouse::Mouse(const Mouse& that)
  : _simulation(that._simulation), x(that.x), y(that.y){
  _pilot = new DefaultPilot(*this);
  std::cout << "Creating copy of mouse" << &that << " new mouse " << this << " with pilot " << _pilot << std::endl;
}

Mouse& Mouse::operator=(const Mouse& that){
  std::cout << "Mouse Assignment operator called" << std::endl;
  this->_simulation = that._simulation;
  this->_pilot = that._pilot;
  this->x = that.x;
  this->y = that.y;
  return *this;
}

Mouse::~Mouse()
{
  std::cout << "Deleting mouse " << this << " with pilot " << _pilot << std::endl; 
  delete _pilot;
};

void Mouse::update()
{
  char m = _pilot->nextMove();
  std::cout << "Updating mouse, move is " << int(m) <<  std::endl; 
}

bool Mouse::move(Direction direction) {
  bool success =  _simulation->canMoveFrom(x, y, direction);
  std::cout << "Move " << int(direction) << " was " << success << std::endl;
  if (success) {
    switch (direction) {
    case 1:
      ++x;
      break;
    case 2:
      ++y;
      break;
    case 4:
      --y;
      break;
    case 8:
      --x;
    }
  }

  std::cout << "Mouse Position is " << x << ", " << y << std::endl;
  return success;
}
