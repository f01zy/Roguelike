#include "Shader.h"
#include "../../../PathConfig.hpp"
#include "../../../Utils/Utils.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int Shader::program = 0;

Shader::Shader(int program, int type) {
  Utils utils;

  this->program = program;

  int success;
  std::string name = "";

  switch (type) {
  case GL_VERTEX_SHADER:
    name = "vertex";
    break;
  case GL_FRAGMENT_SHADER:
    name = "fragment";
    break;
  }

  std::string stringSource = utils.readFile(
      Paths::PROJECT + "/src/Core/Window/Shader/" + name + ".glsl");
  const char *source = stringSource.c_str();

  int shader = glCreateShader(type);
  glShaderSource(shader, 1, &source, nullptr);
  glCompileShader(shader);

  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (!success)
    std::cout << "Shader compilation error" << std::endl;

  glAttachShader(program, shader);
  glDeleteShader(shader);
}

void Shader::use() {
  int success;

  glLinkProgram(program);
  glGetProgramiv(program, GL_LINK_STATUS, &success);
  if (!success)
    std::cout << "Shader program link error" << std::endl;
}
