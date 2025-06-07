#pragma once

#include "../Utils/RoomsMovement.h"
#include <vector>

class Map;
class Rectangle;

class Minimap final {
public:
  Minimap();
  void render();

private:
  Map &map;
  RoomsMovement roomMovement;

  const int minimapX = 10;
  const int minimapY = 10;
  const int minimapPadding = 10;
  const int minimapBlockSize = 20;
  std::vector<std::vector<Rectangle *>> minimapBlocks;

  void updateBlocks(int);
};
