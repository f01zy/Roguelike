#pragma once

#include "../../../Entities/Entity.h"
#include "../../../Entities/EntityManager/EntityManager.h"
#include "../../../Figures/Rectangle/Rectangle.h"
#include "../../../Map/Map.h"
#include "../../../PathConfig.hpp"
#include <memory>
#include <vector>

class Scene final {
public:
  Scene(EntityManager *, Map *, int, int);
  bool checkCollisions(Entity &, glm::vec2, int, int);
  void render();

private:
  int width, height;

  Map *map;
  EntityManager *entityManager;

  std::vector<std::vector<Rectangle *>> objects;

  void renderObjects();
  void clearObjects();
  void initializeObject(int, int, int, int);
};
