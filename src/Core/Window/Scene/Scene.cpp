#include "Scene.h"
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>

Scene::Scene(EntityManager *entityManager, int width, int height)
    : walls(Map::roomSide, std::vector<Rectangle *>(Map::roomSide, nullptr)),
      entityManager(entityManager), width(width), height(height) {}

void Scene::initializeWall(float x, float y, float size) {
  float a = x * size;
  float b = y * size;

  walls[y][x] =
      new Rectangle(a, b, size, size, Paths::PROJECT + "/textures/wall.jpg");
}

void Scene::renderRoom() {
  Map map;

  int x = Map::currentRoom % Map::gridSize;
  int y = Map::currentRoom / Map::gridSize;

  int startX, startY, endX, endY;
  map.setRoomCoordinates(x, y, startX, startY, endX, endY);

  float side = std::floor(width / Map::roomSide);

  for (int i = startY; i <= endY; i++) {
    for (int j = startX; j <= endX; j++) {
      float x = j % 10;
      float y = i % 10;

      if (Map::map[i][j] == '#') {
        if (!walls[y][x])
          initializeWall(x, y, side);

        walls[y][x]->render();
      }
    }
  }
}

void Scene::renderEntity(Entity &entity) {
  Rectangle entityFigure(entity.x, entity.y, entity.width, entity.height);
  entityFigure.render();
}

bool Scene::checkCollision(float ax, float ay, int aw, int ah, float bx,
                           float by, int bw, int bh) {
  bool collisionX = ax + aw >= bx && bx + bw >= ax;
  bool collisionY = ay + ah >= by && by + bh >= ay;

  return collisionX && collisionY;
}

bool Scene::checkEntityCollision(float x, float y, int width, int height) {
  for (auto row : walls) {
    for (auto wall : row) {
      if (wall && checkCollision(x, y, width, height, wall->x, wall->y,
                                 wall->width, wall->height)) {
        std::cout << "collision" << std::endl;
        return true;
      }
    }
  }

  return false;
}

void Scene::render() {
  int moveInAnotherRoom = entityManager->player->checkMovingInAnotherRoom(
      width, height, Map::currentRoom, Map::gridSize);

  if (moveInAnotherRoom != -1) {
    clearWalls();
    int position;

    switch (moveInAnotherRoom) {
    case 0:
      position = Map::currentRoom - 1;
      break;
    case 1:
      position = Map::currentRoom + 1;
      break;
    case 2:
      position = Map::currentRoom - Map::gridSize;
      break;
    case 3:
      position = Map::currentRoom + Map::gridSize;
      break;
    }

    Map::currentRoom = position;
    entityManager->player->moveInAnotherRoom(width, height, moveInAnotherRoom);
  }

  renderRoom();
  renderEntity(*entityManager->player);
}

void Scene::clearWalls() {
  for (int i = 0; i < walls.size(); i++) {
    for (int j = 0; j < walls[i].size(); j++) {
      walls[i][j] = nullptr;
    }
  }
}
