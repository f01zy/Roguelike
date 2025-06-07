#include "Figure.h"
#include "../Assets/Shader/Shader.h"
#include <GL/glew.h>
#include <vector>

Figure::Figure(glm::vec2 position, int width, int height, glm::vec3 color,
               std::string path)
    : position(position), width(width), height(height), color(color),
      path(path) {
  float data[32]{
      position.x,
      position.y,
      0.0f,
      1.0f,
      0.0f,
      color.x,
      color.y,
      color.z,
      position.x + width,
      position.y,
      0.0f,
      0.0f,
      0.0f,
      color.x,
      color.y,
      color.z,
      position.x + width,
      position.y + height,
      0.0f,
      0.0f,
      1.0f,
      color.x,
      color.y,
      color.z,
      position.x,
      position.y + height,
      0.0f,
      1.0f,
      1.0f,
      color.x,
      color.y,
      color.z,
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

void Figure::setPosition(glm::vec2 newPosition) { position = newPosition; }

void Figure::setColor(std::vector<float> newColor) {
  for (int i = 0; i < verticesSize / verticeSize; i++) {
    vertices[i * verticeSize + 5] = newColor[0];
    vertices[i * verticeSize + 6] = newColor[1];
    vertices[i * verticeSize + 7] = newColor[2];
  }

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

glm::vec2 Figure::getPosition() { return position; }
