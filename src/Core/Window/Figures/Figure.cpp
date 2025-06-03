#include "Figure.h"
#include "../Shader/Shader.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/ext/matrix_transform.hpp>
#include <glm/trigonometric.hpp>

Figure::Figure(float x, float y, float size) : x(x), y(y), size(size) {
  float data[20]{
      x,        y,        0.0f, 1.0f, 0.0f, //
      x + size, y,        0.0f, 0.0f, 0.0f, //
      x + size, y + size, 0.0f, 0.0f, 1.0f, //
      x,        y + size, 0.0f, 1.0f, 1.0f  //
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
