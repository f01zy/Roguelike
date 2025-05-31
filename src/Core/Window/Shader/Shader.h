#pragma once

class Shader final {
public:
  Shader(int, int);
  void use();

private:
  int program;
};
