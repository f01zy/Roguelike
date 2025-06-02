#pragma once

class Entity {
public:
  Entity(int, int, int, int, int);

protected:
  int damage;
  int health;
  int armor;
  int width, height;

  int x = 0, y = 0;
};
