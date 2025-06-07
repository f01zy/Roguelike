#pragma once

#include "../Player/Player.h"

class EntityManager final {
public:
  EntityManager();
  static EntityManager &getInstance();

  Player player;
};
