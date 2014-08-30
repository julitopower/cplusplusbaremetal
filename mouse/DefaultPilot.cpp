#include <iostream>
#include <DefaultPilot.hpp>
#include <Mouse.hpp>

DefaultPilot::DefaultPilot(Mouse& mouse)
  : Pilot(mouse), _cellsState(), _previousMoves()
{
  /*
   * During each move the state and previous move are retrieved from the stacks
   * In order to enable the first move we inject a Free state and a none previous
   * move.
   */
  _cellsState.push_back(0);
  _previousMoves.push_back(none);
}

DefaultPilot::~DefaultPilot() {}

/**
 * Given a cell and a direction, it first tries to see wheter
 * that direction has already been tried. If that is not the 
 * case, the mouse is commanded to move into that  direction.
 */
bool DefaultPilot::_tryDirection(char& cellState, Direction dir)
{
  if ((cellState & dir) == 0) {
    cellState |= dir;
    std::cout << "try direction cell state " << int(cellState) << " dir " << int(dir) << std::endl;
    if(_mouse->move(dir))
      return true;
  }
  return false;
}

char DefaultPilot::nextMove(){
  std::cout << "Pilot next move" << std::endl;
  char state = _cellsState.back();
  Direction origin = comesFrom(_previousMoves.back());
  _cellsState.pop_back();
  _previousMoves.pop_back();

  std::cout << "Cell state is " <<  int(state) << std::endl;

  // Try directions, making sure we don't immeditely try the direction
  // we came from.
  Direction dir = none;
  if (origin != right && _tryDirection(state, right))
    dir =  right;     
  else if (origin != down && _tryDirection(state, down))
    dir = down;
  else if (origin != up && _tryDirection(state, up))
    dir = up;
  else if (origin != left && _tryDirection(state, left)) {
    dir = left;
  }

  // Retry origin direction if it is the only one left
  if(dir == none && _tryDirection(state, origin)) {
    std::cout << "No possible move, so I tried origin and succeeded :(" << std::endl;
    dir =  origin;
  }

  // I am living a cell that is exausted, and there are no cycles
  if (dir != none && state == 15)
  {
    std::cout << "Unstacking state afte exausting all options, last dir " << int(dir) << std::endl;
  }
  // I am leaving a cell that is not exausted, therefore I am going to a new cell
  else if (dir != none && state != 15)
  {
    _cellsState.push_back(state);
    _previousMoves.push_back(comesFrom(origin));

    _cellsState.push_back(0);
    _previousMoves.push_back(dir);
  }
  // I am staying in the same cell
  else if (dir == none)
  {
    _cellsState.push_back(state);
    _previousMoves.push_back(comesFrom(origin));
  }
  return dir;
}
