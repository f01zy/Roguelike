#pragma once

#include "../Shader/Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>

class Figure {
public:
  const int width, height;

  Figure(int, int, int, int);
  Figure(Figure &figure) = delete;

  void translate(glm::vec3);
  void rotate(float, glm::vec3);
  void scale(glm::vec3);

  void setPosition(int, int);
  std::vector<int> getPosition();

protected:
  int x = 0;
  int y = 0;

  float vertices[20];
  unsigned VAO, VBO, EBO;
  unsigned texture{};

private:
  glm::mat4 transform;

  void use();
};
