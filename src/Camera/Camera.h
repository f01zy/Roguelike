#pragma once

#include <glm/glm.hpp>

class Entity;

class Camera final {
public:
  Camera(Entity &, int, int);
  Camera(Camera &) = delete;
  static Camera getInstance();
  void update();

private:
  const int width, height;
  Entity &entity;
  glm::vec2 position;
};
