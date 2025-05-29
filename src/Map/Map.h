#pragma once

#include <vector>

class Map final {
public:
  static std::vector<std::vector<char>> map;
  static std::vector<bool> createdBlocksMap;

  Map();
  void generate();

private:
  int blocks = 0;
  int blocksToSquare = 0;
  int gridSize = 0;
  int countSymbolsInLine = 0;

  int minBlocks = 6;
  int maxBlocks = 6;
  int blockSide = 10;
  int corridorWidth = 6;
  int corridorLength = 10;

  bool block(int);
  void initMaps();
};
