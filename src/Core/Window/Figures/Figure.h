#pragma once

#include "../Shader/Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <vector>

class Figure {
public:
  const int width, height;

  Figure(int, int, int, int, std::vector<float> = {0.0f, 0.0f, 0.0f},
         std::string = "");
  Figure(Figure &figure) = delete;

  void translate(glm::vec3);
  void rotate(float, glm::vec3);
  void scale(glm::vec3);
  void setColor(std::vector<float>);

  void setPosition(int, int);
  std::vector<int> getPosition();

protected:
  static const int verticesSize = 32;

  int x = 0;
  int y = 0;

  std::vector<float> color;
  std::string path;

  float vertices[verticesSize];
  unsigned VAO, VBO, EBO;
  unsigned texture = 0;

private:
  glm::mat4 transform;

  void use();
};
