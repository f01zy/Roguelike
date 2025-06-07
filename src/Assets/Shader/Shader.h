#pragma once

class Shader final {
public:
  static int program;

  Shader(int, int);
  void use();
};
