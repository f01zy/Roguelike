#pragma once

class Entity {
public:
  float damage;
  float health;
  float armor;
  float speed;
  float size;

  float x = 300, y = 300;

  Entity(float, float, float, float, float);
  Entity(Entity &) = delete;

  void top();
  void bottom();
  void left();
  void right();
};
