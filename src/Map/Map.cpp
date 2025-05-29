#include "Map.h"
#include "../Utils/Utils.h"
#include <cmath>
#include <vector>

Map::Map() {}

std::vector<std::vector<char>> Map::map{};
std::vector<bool> Map::createdBlocksMap{};

void Map::generate() {
  Utils utils;

  blocks = utils.random(minBlocks, maxBlocks);
  blocksToSquare = utils.roundToSquare(blocks);
  gridSize = std::sqrt(blocksToSquare);
  countSymbolsInLine = blockSide * gridSize;

  initMaps();

  int position = utils.random(0, blocksToSquare - 1);
  int createdBlocks = 1;

  block(position);

  while (createdBlocks < blocks) {
    int side = utils.random(0, 3);

    // 0 - left
    // 1 - right
    // 2 - top
    // 3 - bottom

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
}

bool Map::block(int position) {
  if (gridSize == 0 || createdBlocksMap[position])
    return false;

  int x = position % gridSize;
  int y = position / gridSize;

  int startX = x * blockSide;
  int startY = y * blockSide;
  int endX = startX + blockSide - 1;
  int endY = startY + blockSide - 1;

  for (int by = 0; by < countSymbolsInLine; by++) {
    for (int bx = 0; bx < countSymbolsInLine; bx++) {
      if ((by >= startY && by <= endY && (bx == startX || bx == endX)) ||
          (bx > startX && bx < endX && (by == startY || by == endY)))
        map[by][bx] = '#';
    }
  }

  createdBlocksMap[position] = true;

  return true;
}

void Map::initMaps() {
  int side = blockSide * gridSize;

  map.resize(side);
  for (auto &row : map) {
    row.resize(side, ' ');
  }

  createdBlocksMap.resize(blocksToSquare, false);
}
