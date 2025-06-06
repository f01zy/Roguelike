#include "EntityManager.h"

EntityManager::EntityManager() {
  player = new Player(glm::vec2(300.0f, 300.0f), 30, 30, 5, 5, 100, 3);
}
