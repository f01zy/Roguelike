#include "Scene.h"
#include "../../../PathConfig.hpp"
#include "../Window.h"
#include <cmath>

Scene::Scene()
    : walls(Map::roomSide, std::vector<Rectangle *>(Map::roomSide, nullptr)) {}

void Scene::initializeWall(float x, float y, float size) {
  float a = x * size;
  float b = y * size;

  walls[y][x] =
      new Rectangle(a, b, size, Paths::PROJECT + "/textures/wall.jpg");
}

void Scene::renderRoom() {
  Map map;

  int x = Map::currentRoom % Map::gridSize;
  int y = Map::currentRoom / Map::gridSize;

  int startX, startY, endX, endY;
  map.setRoomCoordinates(x, y, startX, startY, endX, endY);

  float size = std::floor(Window::width / Map::roomSide);

  for (int i = startY; i <= endY; i++) {
    for (int j = startX; j <= endX; j++) {
      float x = j % 10;
      float y = i % 10;

      if (Map::map[i][j] == '#') {
        if (!walls[y][x]) {
          initializeWall(x, y, size);
        }

        walls[y][x]->render();
      }
    }
  }
}

void Scene::renderEntity(Entity &entity) {
  Rectangle entityFigure(entity.x, entity.y, entity.width);
  entityFigure.render();
}
