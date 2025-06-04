#pragma once

#include "../../Entities/EntityManager/EntityManager.h"
#include "../../Utils/Utils.h"
#include "../Window/Scene/Scene.h"
#include <GLFW/glfw3.h>

class Keyboard final {
public:
  Keyboard(EntityManager *, Scene *scene);
  Keyboard(Keyboard &) = delete;

  static void callback(GLFWwindow *, int, int, int, int);
  void handle();

private:
  EntityManager *entityManager;
  Scene *scene;
};
