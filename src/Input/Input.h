#pragma once

#include <GLFW/glfw3.h>

class EntityManager;

class Input final {
public:
  Input();
  Input(Input &) = delete;

  static void callback(GLFWwindow *, int, int, int, int);
  void handleMovement();

  EntityManager &entityManager;
};
