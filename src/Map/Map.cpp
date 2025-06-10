#include "Map.h"
#include "../Types/Variables.h"
#include "../Utils/Utils.h"
#include "Minimap.h"
#include <glm/glm.hpp>

Map::Map() { generate(); }

Map &Map::getInstance() {
  static Map map;
  return map;
}

void Map::generate() {
  Utils utils;

  rooms = utils.random(minRooms, maxRooms);

  initMaps();

  int position = utils.random(0, squareRooms - 1);
  int createdBlocks = 1;
  currentRoom = 0;

  createRoom(position);

  while (createdBlocks < rooms) {
    int side = utils.random(0, 3);

    if ((side == LEFT && position % grid == 0) ||
        (side == RIGHT && (position + 1) % grid == 0) ||
        (side == TOP && position < grid) ||
        (side == BOTTOM && position >= grid * (grid - 1)))
      continue;

    switch (side) {
    case LEFT:
      position--;
      break;
    case RIGHT:
      position++;
      break;
    case TOP:
      position -= grid;
      break;
    case BOTTOM:
      position += grid;
      break;
    }

    if (createRoom(position))
      createdBlocks++;
  }

  makeDoors();
}

bool Map::createRoom(int position) {
  int x = position % grid;
  int y = position / grid;

  if (grid == 0 || createdRooms[y][x])
    return false;

  int startX, startY, endX, endY;
  setRoomCoordinates(x, y, startX, startY, endX, endY);

  if (startX != 0)
    startX--;
  if (startY != 0)
    startY--;

  for (int by = 0; by < map.size(); by++)
    for (int bx = 0; bx < map[by].size(); bx++)
      if ((by >= startY && by <= endY && (bx == startX || bx == endX)) ||
          (bx > startX && bx < endX && (by == startY || by == endY)))
        map[by][bx] = '#';

  createdRooms[y][x] = true;

  return true;
}

void Map::initMaps() {
  int x = blocksInRoomSide * grid;

  map.resize(x);
  for (auto &row : map) {
    row.resize(x, ' ');
  }

  createdRooms.resize(grid);
  for (auto &row : createdRooms) {
    row.resize(grid, false);
  }
}

void Map::makeDoors() {
  for (int i = 0; i < createdRooms.size(); i++) {
    for (int j = 0; j < createdRooms[i].size(); j++) {
      bool block = createdRooms[i][j];

      if (!block)
        continue;

      bool sides[4]{};

      if (j != 0 && createdRooms[i][j - 1])
        sides[LEFT] = true;
      if (j != grid - 1 && createdRooms[i][j + 1])
        sides[RIGHT] = true;
      if (i != 0 && createdRooms[i - 1][j])
        sides[TOP] = true;
      if (i != grid - 1 && createdRooms[i + 1][j])
        sides[BOTTOM] = true;

      for (int k = 0; k < 4; k++)
        if (sides[k])
          makeDoorInCertainRoom(j, i, k);
    }
  }
}

void Map::makeDoorInCertainRoom(int x, int y, int side) {
  int startX, startY, endX, endY;
  setRoomCoordinates(x, y, startX, startY, endX, endY);

  int center = blocksInRoomSide / 2;
  int dx, dy;

  switch (side) {
  case LEFT:
    dx = startX;
    dy = endY - center;
    break;
  case RIGHT:
    dx = endX;
    dy = endY - center;
    break;
  case TOP:
    dx = endX - center;
    dy = startY;
    break;
  case BOTTOM:
    dx = endX - center;
    dy = endY;
    break;
  }

  map[dy][dx] = ' ';
}

void Map::setRoomCoordinates(int x, int y, int &startX, int &startY, int &endX,
                             int &endY) {
  startX = x * blocksInRoomSide;
  startY = y * blocksInRoomSide;
  endX = startX + blocksInRoomSide - 1;
  endY = startY + blocksInRoomSide - 1;
}

int Map::getCurrentRoom() { return currentRoom; }

void Map::setCurrentRoom(int room) { currentRoom = room; }
