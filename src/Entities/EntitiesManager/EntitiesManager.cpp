#include "EntitiesManager.h"
#include <glm/glm.hpp>

EntitiesManager::EntitiesManager()
    : player(Player(glm::vec2(300.0f, 300.0f), 30, 30, 5, 5, 100, 3)) {}

EntitiesManager &EntitiesManager::getInstance() {
  static EntitiesManager entitiesManager;
  return entitiesManager;
}
