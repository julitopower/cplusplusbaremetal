#ifndef DEFAULT_PILOT
#define DEFAULT_PILOT

#include <vector>
#include <Pilot.hpp>
#include <Map.hpp>

class DefaultPilot : public Pilot
{

public:
  DefaultPilot(Mouse & mouse);
  virtual ~DefaultPilot();
  virtual char nextMove();

private:

  std::vector<char> _cellsState;
  std::vector<Direction> _previousMoves;

  bool _tryDirection(char& cellState, Direction dir);
};

#endif
