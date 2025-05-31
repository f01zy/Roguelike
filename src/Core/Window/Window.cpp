#include "Window.h"
#include "../../PathConfig.hpp"
#include "../../Utils/Utils.h"
#include "../Keyboard/Keyboard.h"
#include "Figures/Triangle/Triangle.h"
#include <iostream>

Window::Window() {}

void Window::initShaders() {
  int success;

  shaderProgram = glCreateProgram();

  loadShader(GL_VERTEX_SHADER, "vertex.glsl");
  loadShader(GL_FRAGMENT_SHADER, "fragment.glsl");

  glLinkProgram(shaderProgram);
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success)
    std::cout << "Shader program link error" << std::endl;
}

void Window::loadShader(int type, std::string name) {
  Utils utils;

  int success;
  std::string stringSource =
      utils.readFile(Paths::SRC + "/Core/Window/shaders/" + name);
  const char *source = stringSource.c_str();

  int shader = glCreateShader(type);
  glShaderSource(shader, 1, &source, nullptr);
  glCompileShader(shader);

  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (!success)
    std::cout << "Shader compilation error" << std::endl;

  glAttachShader(shaderProgram, shader);
  glDeleteShader(shader);
}

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

  initShaders();

  glGenBuffers(1, &VBO);
}

void Window::render() {
  float vertices[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};
  Triangle triangle(vertices, VBO);

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    glClearColor(0.2, 0.2, 0.2, 0.2);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);
    triangle.render();

    glfwSwapBuffers(window);
  }

  glfwTerminate();
}
