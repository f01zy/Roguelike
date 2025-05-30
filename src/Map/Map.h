#pragma once

#include <vector>

class Map final {
public:
  static std::vector<std::vector<char>> map;

  Map();
  void generate();

private:
  int spawn{};
  int blocks{};
  int blocksToSquare{};
  int gridSize{};
  std::vector<std::vector<bool>> createdBlocksMap;

  int minBlocks = 4;
  int maxBlocks = 10;
  int blockSide = 10;

  bool block(int);
  void initMaps();
  void makeDoors();
  void makeDoorInCertainBlock(int, int, int);
  void setBlockCoordinates(int, int, int &, int &, int &, int &);
};
