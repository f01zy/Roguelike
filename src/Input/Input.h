#pragma once

#include <GLFW/glfw3.h>

class EntitiesManager;

class Input final {
public:
  Input();
  Input(Input &) = delete;

  static void callback(GLFWwindow *, int, int, int, int);
  void handleMovement();

  EntitiesManager &entitiesManager;
};
