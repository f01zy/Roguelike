#pragma once

class EntitiesManager;
class Map;

class RoomsMovement {
public:
  RoomsMovement();
  int check();

  EntitiesManager &entitiesManager;
  Map &map;

private:
  int getNewRoomSide();
  int getNewRoom(int);
};
