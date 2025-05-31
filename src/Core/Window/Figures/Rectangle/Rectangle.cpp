#include "Rectangle.h"
#include "../../Window.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

Rectangle::Rectangle(float data[24], unsigned VBO) : VBO(VBO) {
  for (int i = 0; i < 24; i++) {
    verticles[i] = data[i];
  }

  glGenVertexArrays(1, &VAO);
}

void Rectangle::render() {
  glBindVertexArray(VAO);
  glGenBuffers(1, &EBO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(verticles), verticles, GL_DYNAMIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
               GL_DYNAMIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(float) * 6, (void *)0);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 3, GL_FLOAT, false, sizeof(float) * 6,
                        (void *)(sizeof(float) * 3));
  glEnableVertexAttribArray(1);

  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}
