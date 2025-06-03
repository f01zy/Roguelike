#include "Keyboard.h"
#include "../../Utils/Utils.h"
#include <GLFW/glfw3.h>

Keyboard::Keyboard() {}

void Keyboard::callback(GLFWwindow *window, int key, int scancode, int action,
                        int mode) {
  Utils utils;

  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);

  if (key == GLFW_KEY_W && action == GLFW_REPEAT)
    Window::entityManager->player->top();

  if (key == GLFW_KEY_A && action == GLFW_REPEAT)
    Window::entityManager->player->left();

  if (key == GLFW_KEY_S && action == GLFW_REPEAT)
    Window::entityManager->player->bottom();

  if (key == GLFW_KEY_D && action == GLFW_REPEAT)
    Window::entityManager->player->right();
}
