#pragma once

#include <string>

class Rectangle final {
public:
  Rectangle(float[32], unsigned, std::string texture = "");
  void render();

private:
  unsigned indices[6]{0, 1, 3, 1, 2, 3};
  float verticles[32];
  unsigned VAO, VBO, EBO, texture = 0;
};
