#include "Game.h"
#include "Window.h"

Game::Game() {}

void Game::start() {
  Window window;

  window.init();
  window.render();
}
