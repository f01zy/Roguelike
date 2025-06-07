#include "Map.h"
#include "../Figures/Rectangle/Rectangle.h"
#include "../Utils/Utils.h"
#include <glm/glm.hpp>

Map::Map()
    : miniMapBlocks(maxRooms, std::vector<Rectangle *>(maxRooms, nullptr)) {
  generate();
}

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

    if (createRoom(position))
      createdBlocks++;
  }

  makeDoors();
}

bool Map::createRoom(int position) {
  int x = position % gridSize;
  int y = position / gridSize;

  if (gridSize == 0 || createdRoomsMap[y][x])
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

  createdRoomsMap[y][x] = true;

  return true;
}

void Map::initMaps() {
  int x = roomSide * gridSize;

  map.resize(x);
  for (auto &row : map) {
    row.resize(x, ' ');
  }

  createdRoomsMap.resize(gridSize);
  for (auto &row : createdRoomsMap) {
    row.resize(gridSize, false);
  }
}

void Map::makeDoors() {
  for (int i = 0; i < createdRoomsMap.size(); i++) {
    for (int j = 0; j < createdRoomsMap[i].size(); j++) {
      bool block = createdRoomsMap[i][j];

      if (!block)
        continue;

      bool sides[4]{};

      if (j != 0 && createdRoomsMap[i][j - 1])
        sides[0] = true;
      if (j != gridSize - 1 && createdRoomsMap[i][j + 1])
        sides[1] = true;
      if (i != 0 && createdRoomsMap[i - 1][j])
        sides[2] = true;
      if (i != gridSize - 1 && createdRoomsMap[i + 1][j])
        sides[3] = true;

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

void Map::setRoomCoordinates(int x, int y, int &startX, int &startY, int &endX,
                             int &endY) {
  startX = x * roomSide;
  startY = y * roomSide;
  endX = startX + roomSide - 1;
  endY = startY + roomSide - 1;
}

void Map::renderMiniMap() {
  for (int i = 0; i < createdRoomsMap.size(); i++) {
    for (int j = 0; j < createdRoomsMap[i].size(); j++) {
      if (!createdRoomsMap[i][j])
        continue;

      if (!miniMapBlocks[i][j]) {
        int x = miniMapBlockSize * (j + 1) + miniMapX + miniMapPadding * j;
        int y = miniMapBlockSize * (i + 1) + miniMapY + miniMapPadding * i;

        glm::vec3 color;

        if (getCurrentRoom() == i * getGridSize() + j)
          color = {1.0f, 0.0f, 0.0f};

        else
          color = {0.0f, 0.0f, 0.0f};

        miniMapBlocks[i][j] = new Rectangle(glm::vec2(x, y), miniMapBlockSize,
                                            miniMapBlockSize, color);
      }

      miniMapBlocks[i][j]->render();
    }
  }
}

int Map::getCurrentRoom() { return currentRoom; }

void Map::setCurrentRoom(int room) { currentRoom = room; }

int Map::getGridSize() { return gridSize; }
