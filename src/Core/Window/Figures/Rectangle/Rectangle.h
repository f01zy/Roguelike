#pragma once

class Rectangle final {
public:
  Rectangle(float[12], unsigned);
  void render();

private:
  unsigned indices[6]{0, 1, 3, 1, 2, 3};
  unsigned VAO, VBO, EBO;
  float verticles[12];
};
