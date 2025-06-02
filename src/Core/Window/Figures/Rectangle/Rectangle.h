#pragma once

#include "../Figure.h"
#include <string>

class Rectangle final : public Figure {
public:
  Rectangle(float[20], std::string texture = "");
  void render();

private:
  unsigned indices[6]{0, 1, 3, 1, 2, 3};
};
