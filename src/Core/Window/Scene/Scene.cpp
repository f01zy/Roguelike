#include "Scene.h"
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>
#include <vector>

Scene::Scene(EntityManager *entityManager, int width, int height)
    : walls(Map::roomSide, std::vector<Rectangle *>(Map::roomSide, nullptr)),
      mapBlocks(20, std::vector<Rectangle *>(20, nullptr)),
      entityManager(entityManager), width(width), height(height) {}

void Scene::initializeWall(int x, int y, int width, int height) {
  int a = x * width;
  int b = y * height;

  walls[y][x] =
      new Rectangle(a, b, width, height, std::vector<float>{0.0f, 0.0f, 0.0f},
                    Paths::PROJECT + "/textures/wall.jpg");
}

void Scene::renderRoom() {
  Map map;

  int x = Map::getCurrentRoom() % Map::getGridSize();
  int y = Map::getCurrentRoom() / Map::getGridSize();

  int startX, startY, endX, endY;
  map.setRoomCoordinates(x, y, startX, startY, endX, endY);

  int side = std::floor(width / Map::roomSide);

  for (int i = startY; i <= endY; i++) {
    for (int j = startX; j <= endX; j++) {
      int x = j % 10;
      int y = i % 10;

      if (Map::map[i][j] == '#') {
        if (!walls[y][x])
          initializeWall(x, y, side, side);

        walls[y][x]->render();
      }
    }
  }
}

void Scene::renderEntity(Entity &entity) {
  std::vector<int> position = entity.getPosition();

  Rectangle entityFigure(position[0], position[1], entity.width, entity.height);
  entityFigure.render();
}

bool Scene::checkCollision(int ax, int ay, int aw, int ah, int bx, int by,
                           int bw, int bh) {
  bool collisionX = ax + aw >= bx && bx + bw >= ax;
  bool collisionY = ay + ah >= by && by + bh >= ay;

  return collisionX && collisionY;
}

bool Scene::checkEntityCollision(int x, int y, int width, int height) {
  for (auto row : walls) {
    for (auto wall : row) {
      if (!wall)
        continue;

      std::vector<int> position = wall->getPosition();

      if (checkCollision(x, y, width, height, position[0], position[1],
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
      width, height, Map::getCurrentRoom(), Map::getGridSize());

  if (moveInAnotherRoom != -1)
    moveToRoom(moveInAnotherRoom);

  renderRoom();
  renderEntity(*entityManager->player);
  renderMap();
}

void Scene::clearWalls() {
  for (int i = 0; i < walls.size(); i++) {
    for (int j = 0; j < walls[i].size(); j++) {
      walls[i][j] = nullptr;
    }
  }
}

void Scene::renderMap() {
  for (int i = 0; i < Map::createdRoomsMap.size(); i++) {
    for (int j = 0; j < Map::createdRoomsMap[i].size(); j++) {
      if (Map::createdRoomsMap[i][j]) {
        if (!mapBlocks[i][j]) {
          int x = mapBlockSize * (j + 1) + mapX + mapPadding * j;
          int y = mapBlockSize * (i + 1) + mapY + mapPadding * i;

          std::vector<float> color;

          if (Map::getCurrentRoom() == i * Map::getGridSize() + j)
            color = {1.0f, 0.0f, 0.0f};

          else
            color = {0.0f, 0.0f, 0.0f};

          mapBlocks[i][j] =
              new Rectangle(x, y, mapBlockSize, mapBlockSize, color);
        }

        mapBlocks[i][j]->render();
      }
    }
  }
}

void Scene::moveToRoom(int side) {
  clearWalls();
  int room;
  int currentRoom = Map::getCurrentRoom();

  switch (side) {
  case 0:
    room = currentRoom - 1;
    break;
  case 1:
    room = currentRoom + 1;
    break;
  case 2:
    room = currentRoom - Map::getGridSize();
    break;
  case 3:
    room = currentRoom + Map::getGridSize();
    break;
  }

  int ax = room % Map::getGridSize();
  int ay = room / Map::getGridSize();

  int bx = currentRoom % Map::getGridSize();
  int by = currentRoom / Map::getGridSize();

  mapBlocks[by][bx]->setColor(std::vector<float>{0.0f, 0.0f, 0.0f});
  mapBlocks[ay][ax]->setColor(std::vector<float>{1.0f, 0.0f, 0.0f});

  Map::setCurrentRoom(room);
  entityManager->player->moveInAnotherRoom(width, height, side);
}
