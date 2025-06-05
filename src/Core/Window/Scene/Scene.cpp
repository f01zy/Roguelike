#include "Scene.h"
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>
#include <vector>

Scene::Scene(EntityManager *entityManager, Map *map, int width, int height)
    : map(map), objects(map->roomSide * map->getGridSize(),
                        std::vector<Rectangle *>(
                            map->roomSide * map->getGridSize(), nullptr)),
      entityManager(entityManager), width(width), height(height) {}

void Scene::initializeObject(int i, int j, int width, int height) {
  int x = j * width;
  int y = i * height;

  objects[i][j] =
      new Rectangle(glm::vec2(x, y), width, height, glm::vec3(0.0f, 0.0f, 0.0f),
                    Paths::PROJECT + "/textures/wall.jpg");
}

void Scene::renderObjects() {
  int objectSide = std::floor(width / map->roomSide);
  int mapSide = map->roomSide * map->getGridSize() - 1;

  for (int i = 0; i <= mapSide; i++) {
    for (int j = 0; j <= mapSide; j++) {
      if (map->map[i][j] != ' ') {
        if (!objects[i][j]) {
          initializeObject(i, j, objectSide, objectSide);
          std::cout << "initialize object (" << i << ", " << j << ")"
                    << std::endl;
        }

        objects[i][j]->render();
      }
    }
  }
}

bool Scene::checkCollisions(Entity &entity, glm::vec2 position, int width,
                            int height) {
  for (auto row : objects) {
    for (auto object : row) {
      if (!object)
        continue;

      glm::vec2 objectPosition = object->getPosition();

      if (entity.checkCollision(position, width, height, objectPosition,
                                object->width, object->height))
        return true;
    }
  }

  return false;
}

void Scene::render() {
  renderObjects();
  entityManager->player->render();
  map->renderMiniMap();
}

void Scene::clearObjects() {
  for (int i = 0; i < objects.size(); i++) {
    for (int j = 0; j < objects[i].size(); j++) {
      objects[i][j] = nullptr;
    }
  }
}
