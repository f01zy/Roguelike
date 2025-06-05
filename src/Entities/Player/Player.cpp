#include "Player.h"

Player::Player(glm::vec2 position, int width, int height, float damage,
               float armor, float health, float speed)
    : Entity(position, width, height, damage, armor, health, speed) {}
