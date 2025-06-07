#include "Map.h"
#include "../Types/Types.h"
#include "../Utils/Utils.h"
#include "Minimap.h"
#include <glm/glm.hpp>

Map::Map() : minimap(Minimap(*this)) { generate(); }

Map &Map::getInstance() {
  static Map map;
  return map;
}

void Map::generate() {
  Utils utils;

  rooms = utils.random(minRooms, maxRooms);
  roomsToSquare = utils.roundToSquare(rooms);
  gridSize = std::sqrt(roomsToSquare);

  initMaps();

  int position = utils.random(0, roomsToSquare - 1);
  int createdBlocks = 1;
  currentRoom = position;

  createRoom(position);

  while (createdBlocks < rooms) {
    int side = utils.random(0, 3);

    if ((side == LEFT && position % gridSize == 0) ||
        (side == RIGHT && (position + 1) % gridSize == 0) ||
        (side == TOP && position < gridSize) ||
        (side == BOTTOM && position >= gridSize * (gridSize - 1)))
      continue;

    switch (side) {
    case LEFT:
      position--;
      break;
    case RIGHT:
      position++;
      break;
    case TOP:
      position -= gridSize;
      break;
    case BOTTOM:
      position += gridSize;
      break;
    }

    if (createRoom(position))
      createdBlocks++;
  }

  makeDoors();
}

bool Map::createRoom(int position) {
  int x = position % gridSize;
  int y = position / gridSize;

  if (gridSize == 0 || createdRooms[y][x])
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
  int x = roomSide * gridSize;

  map.resize(x);
  for (auto &row : map) {
    row.resize(x, ' ');
  }

  createdRooms.resize(gridSize);
  for (auto &row : createdRooms) {
    row.resize(gridSize, false);
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
      if (j != gridSize - 1 && createdRooms[i][j + 1])
        sides[RIGHT] = true;
      if (i != 0 && createdRooms[i - 1][j])
        sides[TOP] = true;
      if (i != gridSize - 1 && createdRooms[i + 1][j])
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

  int center = roomSide / 2;
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
  startX = x * roomSide;
  startY = y * roomSide;
  endX = startX + roomSide - 1;
  endY = startY + roomSide - 1;
}

int Map::getCurrentRoom() { return currentRoom; }

void Map::setCurrentRoom(int room) { currentRoom = room; }

int Map::getGridSize() { return gridSize; }

void Map::renderMinimap() { minimap.render(); }
