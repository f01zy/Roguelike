#include "Minimap.h"
#include "../Figures/Rectangle/Rectangle.h"
#include "../Types/Variables.h"
#include "Map.h"
#include <glm/glm.hpp>

Minimap::Minimap()
    : roomMovement(RoomsMovement()), map(Map::getInstance()),
      minimapBlocks(map.maxRooms,
                    std::vector<Rectangle *>(map.maxRooms, nullptr)) {}

void Minimap::updateBlocks(int newRoom) {
  int currentRoom = map.getCurrentRoom();

  int x = newRoom % map.grid;
  int y = newRoom / map.grid;

  // delete minimapBlocks[y][x];
  minimapBlocks[y][x]->setColor(std::vector<float>{1.0f, 0.0f, 0.0f});

  x = currentRoom % map.grid;
  y = currentRoom / map.grid;

  // delete minimapBlocks[y][x];
  minimapBlocks[y][x]->setColor(std::vector<float>{0.0f, 0.0f, 0.0f});
}

void Minimap::render() {
  int currentRoom = map.getCurrentRoom();
  int newRoom = roomMovement.check();

  if (currentRoom != newRoom) {
    updateBlocks(newRoom);
    map.setCurrentRoom(newRoom);
  }

  for (int i = 0; i < map.grid; i++) {
    for (int j = 0; j < map.grid; j++) {
      if (!map.createdRooms[i][j])
        continue;

      if (!minimapBlocks[i][j]) {
        int x = minimapBlockSize * (j + 1) + minimapX + minimapPadding * j;
        int y = minimapBlockSize * (i + 1) + minimapY + minimapPadding * i;

        glm::vec3 color;

        if (map.getCurrentRoom() == i * map.grid + j)
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
