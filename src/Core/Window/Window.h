#pragma once
#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

class Window final {
public:
  const int width = 500;
  const int height = 500;

  Window();
  void init();
  void render();

private:
  int shaderProgram;
  unsigned VBO;
  GLFWwindow *window;

  void initShaders();
  void loadShader(int, std::string);
};
