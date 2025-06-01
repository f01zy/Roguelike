#include "Window.h"
#include "../../PathConfig.hpp"
#include "../Keyboard/Keyboard.h"
#include "Figures/Rectangle/Rectangle.h"
#include "Shader/Shader.h"
#include <iostream>

Window::Window() {}

void Window::init() {
  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, false);

  window = glfwCreateWindow(width, height, "Roguelike", nullptr, nullptr);
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

  glViewport(0, 0, width, height);
  glfwSetKeyCallback(window, Keyboard::callback);

  program = glCreateProgram();
  Shader(program, GL_VERTEX_SHADER).use();
  Shader(program, GL_FRAGMENT_SHADER).use();
}

void Window::render() {
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(program);

    float vertices[64] = {
        0.7f,  0.3f,  0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, //
        0.7f,  -0.3f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, //
        0.1f,  -0.3f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, //
        0.1f,  0.3f,  0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, //

        -0.7f, 0.3f,  0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, //
        -0.7f, -0.3f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, //
        -0.1f, -0.3f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, //
        -0.1f, 0.3f,  0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f  //
    };

    Rectangle(&vertices[0], Paths::PROJECT + "/textures/floor.jpg").render();
    Rectangle(&vertices[32], Paths::PROJECT + "/textures/container.jpg")
        .render();

    glfwSwapBuffers(window);
  }

  glfwTerminate();
}
