#include "Map.h"
#include "../Utils/Utils.h"
#include <cmath>
#include <vector>

Map::Map() {}

void Map::generate() {
  Utils utils;

  blocks = utils.random(6, 12);
  blocksToSquare = utils.roundToSquare(blocks);
  gridSize = std::sqrt(blocksToSquare);
  countSymbolsInLine = blockSide * gridSize;

  initMap();

  int position = utils.random(0, blocksToSquare - 1);
  int createdBlocks = 1;

  block(position);

  while (createdBlocks < blocks) {
    int side = utils.random(0, 3);

    // 0 - left
    // 1 - right
    // 2 - top
    // 3 - bottom

    if (int adaptivePosition = position + 1;
        (side == 0 && (adaptivePosition - 1) % gridSize == 0) ||
        (side == 1 && adaptivePosition % gridSize == 0) ||
        (side == 2 && adaptivePosition / gridSize <= 1) ||
        (side == 3 && adaptivePosition / gridSize > 2))
      continue;

    switch (side) {
    case 0:
      position--;
    case 1:
      position++;
    case 2:
      position -= gridSize;
    case 3:
      position += gridSize;
    }

    block(position);
    createdBlocks++;
  }
}

void Map::block(int position) {
  if (gridSize == 0)
    return;

  int x = position % gridSize;
  int y = position / gridSize;

  int startX = x * blockSide;
  int startY = y * blockSide;
  int endX = startX + blockSide;
  int endY = startY + blockSide;

  for (int i = 0; i < countSymbolsInLine; i++) {
    int by = i / (blockSide * gridSize);

    for (int j = 0; j < countSymbolsInLine; j++) {
      int bx = i % (blockSide * gridSize);

      if ((by > startY && by < endY && (bx == startX || bx == endX)) ||
          (bx > startX && bx < endX && (by == startY || by == endY)))
        map[by][bx] = '#';
    }
  }
}

void Map::initMap() {
  int side = blockSide * gridSize;

  map.resize(side);

  for (auto &row : map) {
    row.resize(side, ' ');
  }
}
