#include "Camera.h"
#include "../Assets/Shader/Shader.h"
#include "../Entities/Entity.h"
#include <GL/glew.h>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Camera::Camera(Entity &entity, int width, int height)
    : position(glm::vec2(0.0f, 0.0f)), entity(entity), width(width),
      height(height) {
  glm::mat4 projection = glm::ortho(0.0f, (float)width, (float)height, 0.0f);
  glUniformMatrix4fv(glGetUniformLocation(Shader::program, "projection"), 1,
                     GL_FALSE, glm::value_ptr(projection));
}

void Camera::update() {
  glm::vec2 entityPosition = entity.getPosition();
  int offsetX = std::floor(width / 2) - std::floor(entity.width / 2);
  int offsetY = std::floor(height / 2) - std::floor(entity.height / 2);
  position.x = entityPosition.x - offsetX;
  position.y = entityPosition.y - offsetY;
  glm::mat4 view = glm::translate(glm::mat4(1.0f), -glm::vec3(position, 0.0f));

  unsigned location = glGetUniformLocation(Shader::program, "view");
  glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(view));
}
