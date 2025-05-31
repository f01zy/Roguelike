#include "Triangle.h"
#include "../../Window/Window.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

Triangle::Triangle(float data[], unsigned VBO) : VBO(VBO) {
  for (int i = 0; i < 9; i++) {
    verticles[i] = data[i];
  }

  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(verticles), verticles, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(float) * 3, (void *)0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}

void Triangle::render() {
  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, 3);
  glBindVertexArray(0);
}
