#pragma once

class EntityManager;
class Map;

class RoomsMovement {
public:
  RoomsMovement();
  int check();

  EntityManager &entityManager;
  Map &map;

private:
  int getNewRoomSide();
  int getNewRoom(int);
};
