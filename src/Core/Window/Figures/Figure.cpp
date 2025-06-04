#include "Figure.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/ext/matrix_transform.hpp>
#include <glm/trigonometric.hpp>

Figure::Figure(int x, int y, int width, int height)
    : x(x), y(y), width(width), height(height) {
  float data[20]{
      (float)x,         (float)y,          0.0f, 1.0f, 0.0f, //
      (float)x + width, (float)y,          0.0f, 0.0f, 0.0f, //
      (float)x + width, (float)y + height, 0.0f, 0.0f, 1.0f, //
      (float)x,         (float)y + height, 0.0f, 1.0f, 1.0f  //
  };

  for (int i = 0; i < 20; i++) {
    vertices[i] = data[i];
  }

  transform = glm::mat4(1.0f);
  use();
}

void Figure::translate(glm::vec3 vec) {
  transform = glm::translate(transform, vec);
  use();
}

void Figure::rotate(float degrees, glm::vec3 axis) {
  transform = glm::rotate(transform, glm::radians(degrees), axis);
  use();
}

void Figure::scale(glm::vec3 vec) {
  transform = glm::scale(transform, vec);
  use();
}

void Figure::use() {
  unsigned location = glGetUniformLocation(Shader::program, "transform");
  glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(transform));
}

void Figure::setPosition(int ax, int ay) {
  x = ax;
  y = ay;
}

std::vector<int> Figure::getPosition() { return std::vector<int>{x, y}; }
