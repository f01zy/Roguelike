#pragma once

#include "../Assets/Shader/Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>

class Figure {
public:
  const int width, height;

  Figure(glm::vec2, int, int, glm::vec3 = {0.0f, 0.0f, 0.0f}, std::string = "");
  Figure(Figure &figure) = delete;

  void translate(glm::vec3);
  void rotate(float, glm::vec3);
  void scale(glm::vec3);

  void setColor(std::vector<float>);

  void setPosition(glm::vec2);
  glm::vec2 getPosition();

protected:
  glm::vec2 position;
  glm::vec3 color;

  std::string path;

  static const int verticeSize = 8;
  static const int verticesSize = 8 * 4;

  float vertices[verticesSize];

  unsigned VAO, VBO, EBO;
  unsigned texture = 0;

private:
  glm::mat4 transform;

  void use();
};
