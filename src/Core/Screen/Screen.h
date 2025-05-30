#pragma once
#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Screen final {
public:
  int width;
  int height;

  Screen();
  void init();
  void render();

private:
  int shaderProgram;
  unsigned VAO, VBO;
  GLFWwindow *window;
};
