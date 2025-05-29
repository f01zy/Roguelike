#include "Core.h"
#include "../Map/Map.h"
#include "../Utils/Utils.h"
#include <iostream>

Core::Core() {}

void Core::start() {
  Utils utils;
  Map map;

  map.generate();

  while (1) {
    render();
    utils.sleep(0.1);
  }
}

void Core::render() {
  Map map;

  std::cout << map.map.size() << std::endl;
}
