#pragma once

#include "../../../Entities/Entity.h"
#include "../../../Map/Map.h"
#include "../Figures/Rectangle/Rectangle.h"
#include <memory>
#include <vector>

class Scene final {
public:
  std::vector<std::vector<Rectangle *>> walls;

  Scene();
  void renderRoom();
  void renderEntity(Entity &);
  bool checkEntityCollision(float, float, float);

private:
  bool checkCollision(float, float, float, float, float, float);
  void initializeWall(float, float, float);
};
