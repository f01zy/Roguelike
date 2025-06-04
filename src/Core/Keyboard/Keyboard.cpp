#include "Keyboard.h"

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
  float x = entityManager->player->x;
  float y = entityManager->player->y;
  float speed = entityManager->player->speed;
  float width = entityManager->player->width;
  float height = entityManager->player->height;

  if (keys[GLFW_KEY_W])
    y -= speed;

  if (keys[GLFW_KEY_A])
    x -= speed;

  if (keys[GLFW_KEY_S])
    y += speed;

  if (keys[GLFW_KEY_D])
    x += speed;

  if (!scene->checkEntityCollision(x, y, width, height)) {
    entityManager->player->x = x;
    entityManager->player->y = y;
  }
}
