#include "Camera.h"

Camera::Camera(glm::vec2 position, int width, int height, int mapSide)
    : position(position), width(width), height(height), mapSide(mapSide) {}

void Camera::update(Entity &entity) {
  glm::vec2 entityPosition = entity.getPosition();

  int offsetX = std::floor(width / 2) - std::floor(entity.width / 2);
  int offsetY = std::floor(height / 2) - std::floor(entity.height / 2);

  position.x = entityPosition.x - offsetX;
  position.y = entityPosition.y - offsetY;

  float halfScreenWidth = static_cast<float>(width) / 2.0f;
  float halfScreenHeight = static_cast<float>(height) / 2.0f;

  float minX = 0.0f;
  float maxX = static_cast<float>(mapSide) - halfScreenWidth;
  float minY = 0.0f;
  float maxY = static_cast<float>(mapSide) - halfScreenHeight;

  position.x = std::clamp(position.x, minX, maxX);
  position.y = std::clamp(position.y, minY, maxY);

  glm::mat4 view = glm::translate(glm::mat4(1.0f), -glm::vec3(position, 0.0f));
  unsigned location = glGetUniformLocation(Shader::program, "view");

  glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(view));
}
