#include "Window.h"
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

  glGenBuffers(1, &VBO);
}

void Window::render() {
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    glClearColor(0.2, 0.2, 0.2, 0.2);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(program);

    float first[24]{-0.8f, 1.0f, 0.0f,  1.0f, 0.0f,  0.0f, -0.8f, 0.8f,
                    0.0f,  0.0f, 1.0f,  0.0f, -1.0f, 0.8f, 0.0f,  0.0f,
                    0.0f,  1.0f, -1.0f, 1.0f, 0.0f,  0.0f, 0.0f,  0.0f};
    float second[24]{-0.8f, -0.8f, 0.0f,  0.0f,  0.0f,  0.0f,  -0.8f, -1.0f,
                     0.0f,  0.0f,  0.0f,  0.0f,  -1.0f, -1.0f, 0.0f,  0.0f,
                     0.0f,  0.0f,  -1.0f, -0.8f, 0.0f,  0.0f,  0.0f,  0.0f};

    Rectangle(first, VBO).render();
    Rectangle(second, VBO).render();

    glfwSwapBuffers(window);
  }

  glfwTerminate();
}
