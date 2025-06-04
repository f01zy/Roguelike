#pragma once

#include "../Utils/Utils.h"
#include <vector>

class Map final {
public:
  const static int roomSide = 10;
  static std::vector<std::vector<char>> map;

  static void setCurrentRoom(int);
  static int getCurrentRoom();

  static int getGridSize();

  Map();
  void generate();
  void setRoomCoordinates(int, int, int &, int &, int &, int &);

private:
  static int currentRoom;
  static int gridSize;

  int rooms;
  int roomsToSquare;
  std::vector<std::vector<bool>> createdRoomsMap;

  int minRooms = 6;
  int maxRooms = 9;

  bool createRoom(int);
  void initMaps();
  void makeDoors();
  void makeDoorInCertainRoom(int, int, int);
};
