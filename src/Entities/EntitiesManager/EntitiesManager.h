#pragma once

#include "../Player/Player.h"

class EntitiesManager final {
public:
  EntitiesManager();
  static EntitiesManager &getInstance();

  Player player;
};
