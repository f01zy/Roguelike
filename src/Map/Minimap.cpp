#include "Minimap.h"
#include "../Figures/Rectangle/Rectangle.h"
#include "../Types/Types.h"
#include "Map.h"
#include <glm/glm.hpp>

Minimap::Minimap(Map &map)
    : map(map), minimapBlocks(map.maxRooms,
                              std::vector<Rectangle *>(map.maxRooms, nullptr)) {
}

void Minimap::render() {
  for (int i = 0; i < map.getGridSize(); i++) {
    for (int j = 0; j < map.getGridSize(); j++) {
      if (!map.createdRooms[i][j])
        continue;

      if (!minimapBlocks[i][j]) {
        int x = minimapBlockSize * (j + 1) + minimapX + minimapPadding * j;
        int y = minimapBlockSize * (i + 1) + minimapY + minimapPadding * i;

        glm::vec3 color;

        if (map.getCurrentRoom() == i * map.getGridSize() + j)
          color = {1.0f, 0.0f, 0.0f};

        else
          color = {0.0f, 0.0f, 0.0f};

        minimapBlocks[i][j] = new Rectangle(
            glm::vec2(x, y), STATIC, minimapBlockSize, minimapBlockSize, color);
      }

      minimapBlocks[i][j]->render();
    }
  }
}
