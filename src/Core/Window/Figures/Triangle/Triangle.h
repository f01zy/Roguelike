#pragma once

class Triangle final {
public:
  Triangle(float[9], unsigned);
  void render();

private:
  unsigned VAO, VBO;
  float verticles[9];
};
