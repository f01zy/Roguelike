#pragma once

#include "../../PathConfig.hpp"
#include "../../Utils/Utils.h"

class Shader final {
public:
  static int program;

  Shader(int, int);
  void use();
};
