#include "Keyboard.h"
#include "../../Utils/Utils.h"
#include <GLFW/glfw3.h>

Keyboard::Keyboard() {}

void Keyboard::callback(GLFWwindow *window, int key, int scancode, int action,
                        int mode) {
  Utils utils;

  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
}
