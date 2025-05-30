#include "Core.h"
#include "../Map/Map.h"
#include "../Utils/Utils.h"
#include <iostream>

Core::Core() {}

void Core::start() {
  Utils utils;
  Map map;

  utils.clear();
  map.generate();

  while (1) {
    render();
    utils.sleep(10);
  }
}

void Core::render() {
  for (int i = 0; i < Map::map.size(); i++) {
    for (int j = 0; j < Map::map[i].size(); j++) {
      std::cout << Map::map[i][j];
    }
    std::cout << std::endl;
  }
}
