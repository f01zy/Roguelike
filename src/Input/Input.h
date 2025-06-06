#pragma once

#include "../Core/Window/Scene/Scene.h"
#include "../Entities/EntityManager/EntityManager.h"
#include <GLFW/glfw3.h>

class Input final {
public:
  Input(EntityManager *, Scene *scene);
  Input(Input &) = delete;

  static void callback(GLFWwindow *, int, int, int, int);
  void handle();

private:
  EntityManager *entityManager;
  Scene *scene;
};
