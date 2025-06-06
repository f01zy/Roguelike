#pragma once
#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include <string>

#include "../../Assets/Shader/Shader.h"
#include "../../Camera/Camera.h"
#include "../../Entities/EntityManager/EntityManager.h"
#include "../../Input/Input.h"
#include "../../Map/Map.h"
#include "Scene/Scene.h"

class Window final {
public:
  static const int width = 600;
  static const int height = 600;

  EntityManager *entityManager;
  Scene *scene;
  Input *input;
  Map *map;
  Camera *camera;

  Window();
  void init();
  void render();

private:
  int program;
  GLFWwindow *window;
};
