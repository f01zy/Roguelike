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
  const int mapX = 10;
  const int mapY = 10;
  const int mapPadding = 10;
  const int mapBlockSize = 20;

  int width, height;

  EntityManager *entityManager;

  std::vector<std::vector<Rectangle *>> walls;
  std::vector<std::vector<Rectangle *>> mapBlocks;

  void moveToRoom(int side);
  void renderRoom();
  void renderEntity(Entity &);
  bool checkCollision(int, int, int, int, int, int, int, int);
  void initializeWall(int, int, int, int);
  void clearWalls();
  void renderMap();
};
