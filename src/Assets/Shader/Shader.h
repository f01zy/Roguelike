#pragma once

#include "../../PathConfig.hpp"
#include "../../Utils/Utils.h"
#include <GL/glew.h>
#include <iostream>

class Shader final {
public:
  static int program;

  Shader(int, int);
  void use();
};
