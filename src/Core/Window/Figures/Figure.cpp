#include "Figure.h"
#include <GL/glew.h>
#include <GL/glext.h>
#include <GLFW/glfw3.h>
#include <glm/ext/matrix_transform.hpp>
#include <glm/trigonometric.hpp>
#include <vector>

Figure::Figure(int x, int y, int width, int height, std::vector<float> color,
               std::string path)
    : x(x), y(y), width(width), height(height), color(color), path(path) {
  float data[32]{
      (float)x,
      (float)y,
      0.0f,
      1.0f,
      0.0f,
      color[0],
      color[1],
      color[2],
      (float)x + width,
      (float)y,
      0.0f,
      0.0f,
      0.0f,
      color[0],
      color[1],
      color[2],
      (float)x + width,
      (float)y + height,
      0.0f,
      0.0f,
      1.0f,
      color[0],
      color[1],
      color[2],
      (float)x,
      (float)y + height,
      0.0f,
      1.0f,
      1.0f,
      color[0],
      color[1],
      color[2],
  };

  for (int i = 0; i < 32; i++) {
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

void Figure::setColor(std::vector<float> newColor) {
  for (int i = 0; i < verticesSize / 8; i++) {
    vertices[i * 8 + 5] = newColor[0];
    vertices[i * 8 + 6] = newColor[1];
    vertices[i * 8 + 7] = newColor[2];
  }

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

std::vector<int> Figure::getPosition() { return std::vector<int>{x, y}; }
