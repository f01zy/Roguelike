#include "Renderer.h"
#include "../../../Map/Map.h"
#include "../../../PathConfig.hpp"
#include "../Figures/Rectangle/Rectangle.h"
#include "../Window.h"
#include <cmath>

Renderer::Renderer() {}

void Renderer::renderRoom() {
  Map map;

  int x = Map::currentRoom % Map::gridSize;
  int y = Map::currentRoom / Map::gridSize;

  int startX, startY, endX, endY;
  map.setRoomCoordinates(x, y, startX, startY, endX, endY);

  float size = std::floor(Window::width / Map::roomSide);

  for (int i = startY; i <= endY; i++) {
    for (int j = startX; j <= endX; j++) {
      float x = (j % 10) * size;
      float y = (i % 10) * size;

      float vertices[20] = {
          x,        y,        0.0f, 1.0f, 0.0f, //
          x + size, y,        0.0f, 0.0f, 0.0f, //
          x + size, y + size, 0.0f, 0.0f, 1.0f, //
          x,        y + size, 0.0f, 1.0f, 1.0f  //
      };

      if (Map::map[i][j] == '#') {
        Rectangle cube(vertices, Paths::PROJECT + "/textures/wall.jpg");
        cube.render();
      }
    }
  }
}
