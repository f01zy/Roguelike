#pragma once

#include "Minimap.h"
#include <cmath>
#include <vector>

class Rectangle;

class Map final {
public:
  const int squareRooms = 9;
  const int grid = 3;

  const int blockSize = 50;
  const int blocksInRoomSide = 10;
  const int blocksInMapSide = blocksInRoomSide * grid;

  const int minRooms = 4;
  const int maxRooms = 8;

  std::vector<std::vector<char>> map;
  std::vector<std::vector<bool>> createdRooms;

  Map();

  void setCurrentRoom(int);
  int getCurrentRoom();

  static Map &getInstance();
  void generate();

private:
  int currentRoom;
  int rooms;

  void setRoomCoordinates(int, int, int &, int &, int &, int &);
  bool createRoom(int);
  void initMaps();
  void makeDoors();
  void makeDoorInCertainRoom(int, int, int);
};
