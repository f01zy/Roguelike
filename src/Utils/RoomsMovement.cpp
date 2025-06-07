#include "RoomsMovement.h"
#include "../Entities/EntityManager/EntityManager.h"
#include "../Map/Map.h"
#include <glm/glm.hpp>

RoomsMovement::RoomsMovement()
    : map(Map::getInstance()), entityManager(EntityManager::getInstance()) {}

int RoomsMovement::getNewRoomSide() {
  glm::vec2 position = entityManager.player.getPosition();

  int width = entityManager.player.width;
  int height = entityManager.player.height;

  int currentRoom = map.getCurrentRoom();
  int x = currentRoom % map.getGridSize();
  int y = currentRoom / map.getGridSize();

  int xMax = map.blockSide * map.roomSide * (x + 1);
  int yMax = map.blockSide * map.roomSide * (y + 1);
  int xMin = map.blockSide * map.roomSide * x;
  int yMin = map.blockSide * map.roomSide * y;

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
    return currentRoom + map.getGridSize();
  case 3:
    return currentRoom - map.getGridSize();
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
