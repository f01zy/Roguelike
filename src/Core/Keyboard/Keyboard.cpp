#include "Keyboard.h"
#include <vector>

bool keys[GLFW_KEY_LAST];

Keyboard::Keyboard(EntityManager *entityManager, Scene *scene)
    : entityManager(entityManager), scene(scene) {}

void Keyboard::callback(GLFWwindow *window, int key, int scancode, int action,
                        int mode) {
  Utils utils;

  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);

  if (action == GLFW_PRESS)
    keys[key] = true;

  else if (action == GLFW_RELEASE)
    keys[key] = false;
}

void Keyboard::handle() {
  std::vector<int> position = entityManager->player->getPosition();
  float speed = entityManager->player->speed;
  float width = entityManager->player->width;
  float height = entityManager->player->height;

  if (keys[GLFW_KEY_W])
    position[1] -= speed;

  if (keys[GLFW_KEY_A])
    position[0] -= speed;

  if (keys[GLFW_KEY_S])
    position[1] += speed;

  if (keys[GLFW_KEY_D])
    position[0] += speed;

  if (!scene->checkEntityCollision(position[0], position[1], width, height)) {
    entityManager->player->setPosition(position[0], position[1]);
  }
}
