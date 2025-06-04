#pragma once

#include "../../../Entities/Entity.h"
#include "../../../Entities/EntityManager/EntityManager.h"
#include "../../../Map/Map.h"
#include "../../../PathConfig.hpp"
#include "../Figures/Rectangle/Rectangle.h"
#include <memory>
#include <vector>

class Scene final {
public:
  Scene(EntityManager *, int, int);
  bool checkEntityCollision(float, float, int, int);
  void render();

private:
  EntityManager *entityManager;
  std::vector<std::vector<Rectangle *>> walls;
  int width, height;

  void renderRoom();
  void renderEntity(Entity &);
  bool checkCollision(float, float, int, int, float, float, int, int);
  void initializeWall(float, float, float);
  void clearWalls();
};
