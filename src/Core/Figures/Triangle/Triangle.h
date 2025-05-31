#pragma once

class Triangle final {
public:
  Triangle(float[], unsigned);
  void render();

private:
  unsigned VAO, VBO;
  float verticles[9];
};
