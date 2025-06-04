#pragma once

#include "../Entity.h"

class Player : public Entity {
public:
  Player(int, int, float, float, float, float);
  int checkMovingInAnotherRoom(int, int, int, int);
  void moveInAnotherRoom(int, int, int);
};
