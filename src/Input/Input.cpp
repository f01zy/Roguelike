#include "Input.h"
#include "../Entities/EntityManager/EntityManager.h"
#include "../Utils/Collision.h"

bool keys[GLFW_KEY_LAST];

Input::Input() : entityManager(EntityManager::getInstance()) {}

void Input::callback(GLFWwindow *window, int key, int scancode, int action,
                     int mode) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);

  if (action == GLFW_PRESS)
    keys[key] = true;

  else if (action == GLFW_RELEASE)
    keys[key] = false;
}

void Input::handleMovement() {
  Collision collision;

  glm::vec2 position = entityManager.player.getPosition();
  float speed = entityManager.player.speed;
  float width = entityManager.player.width;
  float height = entityManager.player.height;

  if (keys[GLFW_KEY_W])
    position.y -= speed;

  if (keys[GLFW_KEY_A])
    position.x -= speed;

  if (keys[GLFW_KEY_S])
    position.y += speed;

  if (keys[GLFW_KEY_D])
    position.x += speed;

  if (!collision.checkAllObjectsCollision(entityManager.player)) {
    entityManager.player.setPosition(position);
  }
}
