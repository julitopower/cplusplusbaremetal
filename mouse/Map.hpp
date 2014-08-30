#ifndef MAP
#define MAP

#include <vector>

enum Direction {
  none = 0, right = 1, down = 2, up = 4, left = 8, all = 15
};

class Map {
public:
  Map(const std::vector<char>& map, int sizeX, int sizeY);
  bool canMoveFrom(const int x, const int y, const Direction dir) const;
  void print(int x = -1, int y = -1) const;
private:
  const std::vector<char>& _map;
  const int _sizeX;
  const int _sizeY;

  //No copy constructor or assigment operator
  Map(const Map& m);
  Map& operator=(const Map& that);
};

#endif
