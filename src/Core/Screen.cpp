#include "Screen.h"
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>

Screen::Screen() {}

void keyCallback(GLFWwindow *window, int key, int scancode, int action,
                 int mode) {}

void Screen::init() {
  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  window = glfwCreateWindow(800, 600, "Roguelike", nullptr, nullptr);
  if (window == nullptr) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    exit(1);
  }

  glfwMakeContextCurrent(window);

  glewExperimental = true;
  if (glewInit() != GLEW_OK) {
    std::cout << "Failed to initialize GLEW" << std::endl;
    exit(1);
  }

  glfwGetFramebufferSize(window, &width, &height);
  glViewport(0, 0, width, height);

  glfwSetKeyCallback(window, keyCallback);
}

void Screen::render() {
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    glClearColor(0.2, 0.2, 0.2, 0.2);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
  }

  glfwTerminate();
}
