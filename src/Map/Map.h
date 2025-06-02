#pragma once

#include <vector>

class Map final {
public:
  static std::vector<std::vector<char>> map;
  static int currentRoom;
  static int gridSize;
  const static int roomSide = 10;

  Map();
  void generate();
  void setRoomCoordinates(int, int, int &, int &, int &, int &);

private:
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
