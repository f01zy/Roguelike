#pragma once

#include <vector>
class Entity {
public:
  const float damage;
  const float health;
  const float armor;
  const float speed;
  const int width, height;

  Entity(int, int, float, float, float, float);
  Entity(Entity &) = delete;

  void setPosition(int, int);
  std::vector<int> getPosition();

protected:
  int x = 300;
  int y = 300;
};
