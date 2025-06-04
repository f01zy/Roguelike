#pragma once

#include "../../Texture/Texture.h"
#include "../Figure.h"
#include <string>

class Rectangle final : public Figure {
public:
  Rectangle(float, float, int, int, std::string texture = "");
  void render();

private:
  unsigned indices[6]{0, 1, 3, 1, 2, 3};
};
