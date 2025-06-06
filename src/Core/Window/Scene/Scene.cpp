#include "Scene.h"

Scene::Scene(EntityManager *entityManager, Map *map, Camera *camera, int width,
             int height)
    : camera(camera), map(map),
      objects(map->roomSide * map->getGridSize(),
              std::vector<Rectangle *>(map->roomSide * map->getGridSize(),
                                       nullptr)),
      entityManager(entityManager), width(width), height(height) {}

void Scene::init() { initObjects(); }

void Scene::initializeObject(int i, int j, int width, int height) {
  int x = j * width;
  int y = i * height;

  objects[i][j] =
      new Rectangle(glm::vec2(x, y), width, height, glm::vec3(0.0f, 0.0f, 0.0f),
                    Paths::PROJECT + "/textures/wall.jpg");
}

void Scene::clearObjects() {
  for (int i = 0; i < objects.size(); i++) {
    for (int j = 0; j < objects[i].size(); j++) {
      objects[i][j] = nullptr;
    }
  }
}

void Scene::initObjects() {
  int mapSide = map->roomSide * map->getGridSize();

  for (int i = 0; i < mapSide; i++) {
    for (int j = 0; j < mapSide; j++) {
      if (map->map[i][j] != ' ') {
        initializeObject(i, j, map->blockSide, map->blockSide);
        std::cout << "initialize object (" << i << ", " << j << ")"
                  << std::endl;
        continue;
      }

      std::cout << "skip object (" << i << ", " << j << ")" << std::endl;
    }
  }
}

void Scene::renderObjects() {
  int mapSide = map->roomSide * map->getGridSize();

  for (int i = 0; i < mapSide; i++)
    for (int j = 0; j < mapSide; j++)
      if (map->map[i][j] != ' ')
        objects[i][j]->render();
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
  camera->update(*entityManager->player);

  // map->renderMiniMap();
}
