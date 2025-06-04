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
  bool checkEntityCollision(int, int, int, int);
  void render();

private:
  EntityManager *entityManager;
  std::vector<std::vector<Rectangle *>> walls;
  int width, height;

  void renderRoom();
  void renderEntity(Entity &);
  bool checkCollision(int, int, int, int, int, int, int, int);
  void initializeWall(int, int, int, int);
  void clearWalls();
};
