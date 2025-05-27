#include "Core.h"
#include "../Utils/Utils.h"
#include <iostream>

Core::Core() {}

void Core::start() {
  Utils utils;

  while (1) {
    this->render();
    utils.sleep(0.1);
  }
}

void Core::render() {
  // ...
  std::cout << "Render" << std::endl;
}
