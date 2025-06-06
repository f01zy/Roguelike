#include "Rectangle.h"

Rectangle::Rectangle(glm::vec2 position, int width, int height, glm::vec3 color,
                     std::string path)
    : Figure(position, width, height, color, path) {

  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glGenBuffers(1, &EBO);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
               GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(float) * verticeSize,
                        (void *)0);

  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 2, GL_FLOAT, false, sizeof(float) * verticeSize,
                        (void *)(sizeof(float) * 3));

  glEnableVertexAttribArray(2);
  glVertexAttribPointer(2, 3, GL_FLOAT, false, sizeof(float) * verticeSize,
                        (void *)(sizeof(float) * 5));

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  if (path.size() != 0)
    Texture(path, texture);
}

void Rectangle::render() {
  glBindVertexArray(VAO);

  int useTexturePosition = glGetUniformLocation(Shader::program, "useTexture");

  if (path.size() != 0)
    glUniform1i(useTexturePosition, 1);

  else
    glUniform1i(useTexturePosition, 0);

  glBindTexture(GL_TEXTURE_2D, texture);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

  glBindVertexArray(0);
}
