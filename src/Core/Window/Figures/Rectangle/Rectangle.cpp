#include "Rectangle.h"
#include "../../Texture/Texture.h"
#include "../../Window.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>

Rectangle::Rectangle(float data[32], unsigned VBO, std::string path)
    : VBO(VBO) {
  for (int i = 0; i < 32; i++) {
    verticles[i] = data[i];
  }

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &EBO);

  if (path.size() != 0)
    Texture(path, texture);
}

void Rectangle::render() {
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(verticles), verticles, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
               GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(float) * 8, (void *)0);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 3, GL_FLOAT, false, sizeof(float) * 8,
                        (void *)(sizeof(float) * 3));
  glEnableVertexAttribArray(1);

  glVertexAttribPointer(2, 2, GL_FLOAT, false, sizeof(float) * 8,
                        (void *)(sizeof(float) * 6));

  if (texture != 0)
    glEnableVertexAttribArray(2);

  glBindTexture(GL_TEXTURE_2D, texture);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}
