#pragma once

class Triangle final {
public:
  Triangle(float[18], unsigned);
  void render();

private:
  float verticles[18];
  unsigned VAO, VBO;
};
