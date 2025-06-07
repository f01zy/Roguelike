#include "EntityManager.h"
#include <glm/glm.hpp>

EntityManager::EntityManager()
    : player(Player(glm::vec2(300.0f, 300.0f), 30, 30, 5, 5, 100, 3)) {}

EntityManager &EntityManager::getInstance() {
  static EntityManager entityManager;
  return entityManager;
}
