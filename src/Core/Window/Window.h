#pragma once
#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

class Window final {
public:
  static const int width = 600;
  static const int height = 600;

  Window();
  void init();
  void render();

private:
  int program;
  GLFWwindow *window;
};
