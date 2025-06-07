#pragma once

#include "Minimap.h"
#include <cmath>
#include <vector>

class Rectangle;

class Map final {
public:
  const int roomSide = 13;
  const int blockSide = 50;
  const int minRooms = 6;
  const int maxRooms = 9;

  std::vector<std::vector<char>> map;
  std::vector<std::vector<bool>> createdRooms;

  Map();

  void setCurrentRoom(int);
  int getCurrentRoom();
  int getGridSize();

  static Map &getInstance();
  void generate();
  void renderMinimap();

private:
  Minimap minimap;

  int currentRoom;
  int gridSize;
  int rooms;
  int roomsToSquare;

  void setRoomCoordinates(int, int, int &, int &, int &, int &);
  bool createRoom(int);
  void initMaps();
  void makeDoors();
  void makeDoorInCertainRoom(int, int, int);
};
