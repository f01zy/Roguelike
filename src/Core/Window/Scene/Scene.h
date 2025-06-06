#pragma once

#include "../../../Camera/Camera.h"
#include "../../../Entities/Entity.h"
#include "../../../Entities/EntityManager/EntityManager.h"
#include "../../../Figures/Rectangle/Rectangle.h"
#include "../../../Map/Map.h"
#include "../../../PathConfig.hpp"
#include <iostream>
#include <memory>
#include <vector>

class Scene final {
public:
  Scene(EntityManager *, Map *, Camera *, int, int);
  bool checkCollisions(Entity &, glm::vec2, int, int);
  void init();
  void render();

private:
  int width, height;

  Camera *camera;
  Map *map;
  EntityManager *entityManager;

  std::vector<std::vector<Rectangle *>> objects;

  void initObjects();
  void renderObjects();
  void clearObjects();
  void initializeObject(int, int, int, int);
};
