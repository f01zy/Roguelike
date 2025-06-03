#include "Keyboard.h"
#include "../../Utils/Utils.h"
#include <GLFW/glfw3.h>

Keyboard::Keyboard() {}

void Keyboard::callback(GLFWwindow *window, int key, int scancode, int action,
                        int mode) {
  Utils utils;

  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);

  if (action == GLFW_PRESS || action == GLFW_REPEAT) {
    float x = Window::entityManager->player->x;
    float y = Window::entityManager->player->y;
    float speed = Window::entityManager->player->speed;
    float size = Window::entityManager->player->size;

    if (key == GLFW_KEY_W)
      y -= speed;
    if (key == GLFW_KEY_A)
      x -= speed;
    if (key == GLFW_KEY_S)
      y += speed;
    if (key == GLFW_KEY_D)
      x += speed;

    if (!Window::scene->checkEntityCollision(x, y, size)) {
      Window::entityManager->player->x = x;
      Window::entityManager->player->y = y;
    }
  }
}
