#pragma once

#include "../../Texture/Texture.h"
#include "../Figure.h"
#include <string>

class Rectangle final : public Figure {
public:
  Rectangle(int, int, int, int, std::vector<float> = {0.0f, 0.0f, 0.0f},
            std::string = "");
  void render();

private:
  unsigned indices[6]{0, 1, 3, 1, 2, 3};
};
