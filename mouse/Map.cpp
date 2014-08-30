#include <Map.hpp>
#include <iostream>

Map::Map(const std::vector<char>& map, const int sizeX, const int sizeY)
  : _map(map), _sizeX(sizeX), _sizeY(sizeY) {}

// 1 = Left door
// 2 = right door
// 4 = up door
// 8 = down door
bool Map::canMoveFrom(const int x, const int y, const Direction dir) const {
  // Check request is within the boundaries of the map
  if (x >= _sizeX || y >= _sizeY || (y * _sizeX + x > _sizeX * _sizeY))
    return false;

  char currentCell = _map[y * _sizeX + x];
  return (currentCell & dir) != 0;
}

void Map::print(int x, int y) const {
  for (int i = 0 ; i < _sizeY ; ++i) {
    for (int j = 0 ; j < _sizeX ; ++j) {
      std::cout << " ";
      if ((_map[i*_sizeX + j] & 4) == 0)
	std::cout << "=";
      else
	std::cout << "-";
    }
    std::cout << std::endl;
    for (int j = 0 ; j < _sizeX ; ++j) {
      if ((_map[i*_sizeX + j] & 8) == 0)
	std::cout << "I";
      else
	std::cout << "'";
      if(i == y && j == x)
	std::cout << "X";
      else
	std::cout << " ";
      if (j < _sizeX -1)
	continue;
      if ((_map[i*_sizeX + j] & 1) == 0)
	std::cout << "I";
      else
	std::cout << "'";
    }
    std::cout << std::endl;
    if (i <_sizeY -1)
      continue;
    for (int j = 0 ; j < _sizeX ; ++j) {
      std::cout << " ";
      if ((_map[i*_sizeX + j] & 2) == 0)
	std::cout << "=";
      else
	std::cout << "-";
    }
    std::cout << std::endl;
  }

}
