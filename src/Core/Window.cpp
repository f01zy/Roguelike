#include "Window.h"
#include "../Assets/Shader/Shader.h"
#include "../Input/Input.h"
#include "Scene.h"
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
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
  glfwSetKeyCallback(window, Input::callback);

  program = glCreateProgram();
  Shader(program, GL_VERTEX_SHADER).use();
  Shader(program, GL_FRAGMENT_SHADER).use();
  glUseProgram(program);
}

void Window::render() {
  Input input;
  Scene scene(width, height);

  scene.init();

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    input.handleMovement();
    scene.render();

    glfwSwapBuffers(window);
  }

  glfwTerminate();
}
