#include "Core.h"
#include "../Map/Map.h"
#include "../Utils/Utils.h"
#include "Window/Window.h"

Core::Core() {}

void Core::start() {
  Utils utils;
  Map map;
  Window window;

  map.generate();
  window.init();
  window.render();
}
