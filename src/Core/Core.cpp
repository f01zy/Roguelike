#include "Core.h"
#include "../Map/Map.h"
#include "../Utils/Utils.h"
#include "Screen.h"

Core::Core() {}

void Core::start() {
  Utils utils;
  Map map;
  Screen screen;

  map.generate();

  screen.init();
  screen.render();
}
