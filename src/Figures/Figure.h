#pragma once

#include <glm/ext/matrix_transform.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/trigonometric.hpp>
#include <string>

class EntitiesManager;

class Figure {
public:
  const int width, height;

  Figure(glm::vec2, int, int, int, glm::vec3 = {0.0f, 0.0f, 0.0f},
         std::string = "");
  Figure(Figure &figure) = delete;

  void translate(glm::vec3);
  void rotate(float, glm::vec3);
  void scale(glm::vec3);
  void render();

  void setColor(std::vector<float>);
  void setPosition(glm::vec2);
  glm::vec2 getPosition();

protected:
  glm::vec2 position;
  glm::vec3 color;
  std::string path = "";
  int renderType;

  EntitiesManager &entitiesManager;

  static const int verticeSize = 8;
  static const int verticesCount = 4;
  float vertices[verticeSize * verticesCount];

  unsigned VAO, VBO, EBO;
  unsigned texture = 0;

  void setTexture();
  void setRenderTypePosition();

private:
  glm::mat4 transform;
  void use();
};
