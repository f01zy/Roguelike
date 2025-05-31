#include "Triangle.h"
#include "../../Window.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

Triangle::Triangle(float data[18], unsigned VBO) : VBO(VBO) {
  for (int i = 0; i < 18; i++) {
    verticles[i] = data[i];
  }

  glGenVertexArrays(1, &VAO);
}

void Triangle::render() {
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(verticles), verticles, GL_DYNAMIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(float) * 6, (void *)0);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 3, GL_FLOAT, false, sizeof(float) * 6,
                        (void *)(sizeof(float) * 3));
  glEnableVertexAttribArray(1);

  glDrawArrays(GL_TRIANGLES, 0, 3);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}
