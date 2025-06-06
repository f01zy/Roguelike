#pragma once

#include "../../Map/Map.h"
#include "../Player/Player.h"

class EntityManager final {
public:
  EntityManager();

  Player *player;
};
