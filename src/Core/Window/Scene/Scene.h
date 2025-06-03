#pragma once

#include "../../../Entities/Entity.h"
#include "../../../Map/Map.h"
#include "../Figures/Rectangle/Rectangle.h"
#include <memory>
#include <vector>

class Scene final {
public:
  Scene();
  void renderRoom();
  void renderEntity(Entity &entity);

private:
  std::vector<std::vector<Rectangle *>> walls;

  void initializeWall(float, float, float);
};
