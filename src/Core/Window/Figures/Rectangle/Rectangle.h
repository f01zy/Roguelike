#pragma once

class Rectangle final {
public:
  Rectangle(float[24], unsigned);
  void render();

private:
  unsigned indices[6]{0, 1, 3, 1, 2, 3};
  float verticles[24];
  unsigned VAO, VBO, EBO;
};
