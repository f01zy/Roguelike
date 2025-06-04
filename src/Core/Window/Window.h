#pragma once
#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

#include "../../Entities/EntityManager/EntityManager.h"
#include "../Keyboard/Keyboard.h"
#include "Scene/Scene.h"

class Window final {
public:
  static const int width = 600;
  static const int height = 600;

  static EntityManager *entityManager;
  static Scene *scene;
  static Keyboard *keyboard;

  Window();
  void init();
  void render();

private:
  int program;
  GLFWwindow *window;
};
