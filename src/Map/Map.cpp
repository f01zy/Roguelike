// 0 - left
// 1 - right
// 2 - top
// 3 - bottom

#include "Map.h"
#include "../Utils/Utils.h"
#include <cmath>
#include <iostream>
#include <vector>

Map::Map() {}

std::vector<std::vector<char>> Map::map{};

void Map::generate() {
  Utils utils;

  blocks = utils.random(minBlocks, maxBlocks);
  blocksToSquare = utils.roundToSquare(blocks);
  gridSize = std::sqrt(blocksToSquare);

  initMaps();

  int position = utils.random(0, blocksToSquare - 1);
  int createdBlocks = 1;
  spawn = position;

  block(position);

  while (createdBlocks < blocks) {
    int side = utils.random(0, 3);

    if ((side == 0 && position % gridSize == 0) ||
        (side == 1 && (position + 1) % gridSize == 0) ||
        (side == 2 && position < gridSize) ||
        (side == 3 && position >= gridSize * (gridSize - 1)))
      continue;

    switch (side) {
    case 0:
      position--;
      break;
    case 1:
      position++;
      break;
    case 2:
      position -= gridSize;
      break;
    case 3:
      position += gridSize;
      break;
    }

    if (block(position))
      createdBlocks++;
  }

  makeDoors();

  std::cout << "Created blocks:\n";
  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < gridSize; j++) {
      std::cout << (createdBlocksMap[i][j] ? '1' : '0');
    }
    std::cout << '\n';
  }
}

bool Map::block(int position) {
  int x = position % gridSize;
  int y = position / gridSize;

  if (gridSize == 0 || createdBlocksMap[y][x])
    return false;

  int startX, startY, endX, endY;
  setBlockCoordinates(x, y, startX, startY, endX, endY);

  // if (startX != 0)
  //   startX--;
  // if (startY != 0)
  //   startY--;

  for (int by = 0; by < map.size(); by++) {
    for (int bx = 0; bx < map[by].size(); bx++) {
      if ((by >= startY && by <= endY && (bx == startX || bx == endX)) ||
          (bx > startX && bx < endX && (by == startY || by == endY)))
        map[by][bx] = '#';
    }
  }

  createdBlocksMap[y][x] = true;

  return true;
}

void Map::initMaps() {
  int x = blockSide * gridSize;

  map.resize(x);
  for (auto &row : map) {
    row.resize(x, ' ');
  }

  createdBlocksMap.resize(gridSize);
  for (auto &row : createdBlocksMap) {
    row.resize(gridSize, false);
  }
}

void Map::makeDoors() {
  for (int i = 0; i < createdBlocksMap.size(); i++) {
    for (int j = 0; j < createdBlocksMap[i].size(); j++) {
      bool block = createdBlocksMap[i][j];

      if (!block)
        continue;

      bool sides[4]{};

      if (j != 0 && createdBlocksMap[i][j - 1])
        sides[0] = true;
      if (j != gridSize - 1 && createdBlocksMap[i][j + 1])
        sides[1] = true;
      if (i != 0 && createdBlocksMap[i - 1][j])
        sides[2] = true;
      if (i != gridSize - 1 && createdBlocksMap[i + 1][j])
        sides[3] = true;

      for (int k = 0; k < 4; k++) {
        if (sides[k])
          makeDoorInCertainBlock(j, i, k);
      }
    }
  }
}

void Map::makeDoorInCertainBlock(int x, int y, int side) {
  int startX, startY, endX, endY;
  setBlockCoordinates(x, y, startX, startY, endX, endY);

  int center = blockSide / 2;
  // bool isEven = blockSide % 2 == 0;

  int dx, dy;

  switch (side) {
  case 0:
    dx = startX;
    dy = endY - center;
    break;
  case 1:
    dx = endX;
    dy = endY - center;
    break;
  case 2:
    dx = endX - center;
    dy = startY;
    break;
  case 3:
    dx = endX - center;
    dy = endY;
    break;
  }

  map[dy][dx] = ' ';
}

void Map::setBlockCoordinates(int x, int y, int &startX, int &startY, int &endX,
                              int &endY) {
  startX = x * blockSide;
  startY = y * blockSide;
  endX = startX + blockSide - 1;
  endY = startY + blockSide - 1;
}
