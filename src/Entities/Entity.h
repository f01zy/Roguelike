#pragma once

#include "../Figures/Rectangle/Rectangle.h"
#include "glm/glm.hpp"

class Entity {
public:
  const float damage;
  const float health;
  const float armor;
  const float speed;
  const int width, height;

  Entity(glm::vec2, int, int, float, float, float, float);
  Entity(Entity &) = delete;

  void setPosition(glm::vec2);
  glm::vec2 getPosition();

  void render();
  bool checkCollision(glm::vec2, int, int, glm::vec2, int, int);

protected:
  glm::vec2 position = {300.0f, 300.0f};
};
