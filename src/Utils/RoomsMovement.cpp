#include "RoomsMovement.h"
#include "../Entities/EntitiesManager/EntitiesManager.h"
#include "../Map/Map.h"
#include <glm/glm.hpp>

RoomsMovement::RoomsMovement()
    : map(Map::getInstance()), entitiesManager(EntitiesManager::getInstance()) {
}

int RoomsMovement::getNewRoomSide() {
  glm::vec2 position = entitiesManager.player.getPosition();

  int width = entitiesManager.player.width;
  int height = entitiesManager.player.height;

  int currentRoom = map.getCurrentRoom();
  int x = currentRoom % map.grid;
  int y = currentRoom / map.grid;

  int xMax = map.blockSize * map.blocksInRoomSide * (x + 1);
  int yMax = map.blockSize * map.blocksInRoomSide * (y + 1);
  int xMin = map.blockSize * map.blocksInRoomSide * x;
  int yMin = map.blockSize * map.blocksInRoomSide * y;

  bool leftRoom = position.x + width < xMin;
  bool rightRoom = position.x > xMax;
  bool upRoom = position.y + height < yMin;
  bool downRoom = position.y > yMax;

  if (leftRoom)
    return 1;
  else if (rightRoom)
    return 0;
  else if (upRoom)
    return 3;
  else if (downRoom)
    return 2;
  else
    return -1;
}

int RoomsMovement::getNewRoom(int side) {
  int currentRoom = map.getCurrentRoom();
  int newRoom;

  switch (side) {
  case 0:
    return currentRoom + 1;
  case 1:
    return currentRoom - 1;
  case 2:
    return currentRoom + map.grid;
  case 3:
    return currentRoom - map.grid;
  }

  return currentRoom;
}

int RoomsMovement::check() {
  int newRoomSide = getNewRoomSide();
  int currentRoom = map.getCurrentRoom();

  if (newRoomSide != -1)
    return getNewRoom(newRoomSide);

  return currentRoom;
}
