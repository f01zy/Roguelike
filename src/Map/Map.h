#pragma once

#include <vector>

class Map final {
public:
  std::vector<std::vector<char>> map;

  Map();
  void generate();

private:
  int blocks = 0;
  int blocksToSquare = 0;
  int gridSize = 0;
  int countSymbolsInLine = 0;

  int minRooms = 6;
  int maxRooms = 10;
  int blockSide = 10;
  int corridorWidth = 6;
  int corridorLength = 10;

  void block(int);
  void initMap();
};
