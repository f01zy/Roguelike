#pragma once

#include <GLFW/glfw3.h>

class Keyboard final {
public:
  Keyboard();
  static void callback(GLFWwindow *, int, int, int, int);
};
