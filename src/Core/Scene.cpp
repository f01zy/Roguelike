#include "Scene.h"
#include "../Entities/Entity.h"
#include "../Entities/EntityManager/EntityManager.h"
#include "../Figures/Rectangle/Rectangle.h"
#include "../Map/Map.h"
#include "../ObjectsManager/ObjectsManager.h"
#include "../PathConfig.hpp"
#include "../Types/Types.h"
#include <iostream>

Scene::Scene(int width, int height)
    : width(width), height(height),
      objectsManager(ObjectsManager::getInstance()), map(Map::getInstance()),
      entityManager(EntityManager::getInstance()),
      camera(Camera(entityManager.player, width, height)) {}

void Scene::init() {
  glm::vec2 size = objectsManager.size();

  for (int i = 0; i < size.y; i++) {
    for (int j = 0; j < size.x; j++) {
      if (map.map[i][j] != ' ') {
        int x = j * map.blockSide;
        int y = i * map.blockSide;

        objectsManager.add(
            j, i,
            new Rectangle(glm::vec2(x, y), DEFAULT, map.blockSide,
                          map.blockSide, glm::vec3(0.0f, 0.0f, 0.0f),
                          Paths::PROJECT + "/textures/wall.jpg"));

        std::cout << "initialize object (" << i << ", " << j << ")"
                  << std::endl;
      }
    }
  }
}

void Scene::renderObjects() {
  glm::vec2 size = objectsManager.size();

  for (int i = 0; i < size.y; i++) {
    for (int j = 0; j < size.x; j++) {
      if (map.map[i][j] != ' ') {
        objectsManager.get(j, i)->render();
      }
    }
  }
}

void Scene::render() {
  renderObjects();
  entityManager.player.render();
  camera.update();
  map.renderMinimap();
}
