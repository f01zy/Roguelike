#include "Scene.h"
#include "../Entities/EntitiesManager/EntitiesManager.h"
#include "../Entities/Entity.h"
#include "../Figures/Rectangle/Rectangle.h"
#include "../Map/Map.h"
#include "../ObjectsManager/ObjectsManager.h"
#include "../PathConfig.hpp"
#include "../Types/Object.h"
#include "../Types/Variables.h"
#include <iostream>

Scene::Scene(int width, int height)
    : width(width), height(height), minimap(Minimap()),
      objectsManager(ObjectsManager::getInstance()), map(Map::getInstance()),
      entitiesManager(EntitiesManager::getInstance()),
      camera(Camera(entitiesManager.player, width, height)) {}

void Scene::init() {
  glm::vec2 size = objectsManager.size();

  for (int i = 0; i < size.y; i++) {
    for (int j = 0; j < size.x; j++) {
      if (map.map[i][j] == ' ')
        continue;

      int x = j * map.blockSize;
      int y = i * map.blockSize;

      Object *object = new Object();
      object->figure = new Rectangle(glm::vec2(x, y), DEFAULT, map.blockSize,
                                     map.blockSize, glm::vec3(0.0f, 0.0f, 0.0f),
                                     Paths::PROJECT + "/textures/wall.jpg");

      objectsManager.add(j, i, object);

      std::cout << "initialize object (" << i << ", " << j << ")" << std::endl;
    }
  }
}

void Scene::renderObjects() {
  glm::vec2 size = objectsManager.size();

  for (int i = 0; i < size.y; i++) {
    for (int j = 0; j < size.x; j++) {
      Object *object = objectsManager.get(j, i);

      if (object)
        object->figure->render();
    }
  }
}

void Scene::render() {
  renderObjects();
  entitiesManager.player.render();
  camera.update();
  minimap.render();
}
