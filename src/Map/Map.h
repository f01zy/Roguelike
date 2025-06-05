#pragma once

#include "../Figures/Rectangle/Rectangle.h"
#include <vector>

class Map final {
public:
  const int roomSide = 10;

  std::vector<std::vector<char>> map;

  void setCurrentRoom(int);
  int getCurrentRoom();

  int getGridSize();

  Map();
  void generate();
  void renderMiniMap();

private:
  int currentRoom;
  int gridSize;

  int rooms;
  int roomsToSquare;

  int minRooms = 6;
  int maxRooms = 9;

  const int miniMapX = 10;
  const int miniMapY = 10;
  const int miniMapPadding = 10;
  const int miniMapBlockSize = 20;

  std::vector<std::vector<bool>> createdRoomsMap;
  std::vector<std::vector<Rectangle *>> miniMapBlocks;

  void setRoomCoordinates(int, int, int &, int &, int &, int &);
  bool createRoom(int);
  void initMaps();
  void makeDoors();
  void makeDoorInCertainRoom(int, int, int);
};
