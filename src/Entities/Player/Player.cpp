#include "Player.h"

Player::Player(int width, int height, float damage, float armor, float health,
               float speed)
    : Entity(width, height, damage, armor, health, speed) {}

int Player::checkMovingInAnotherRoom(int width, int height, int position,
                                     int gridSize) {
  if (x < 0)
    return 0;

  else if (x > width)
    return 1;

  else if (y < 0)
    return 2;

  else if (y > height)
    return 3;

  return -1;
}

void Player::moveInAnotherRoom(int windowWidth, int windowHeight, int side) {
  switch (side) {
  case 0:
    x = windowHeight - height;
    break;
  case 1:
    x = 0;
    break;
  case 2:
    y = windowWidth - width;
    break;
  case 3:
    y = 0;
    break;
  }
}
