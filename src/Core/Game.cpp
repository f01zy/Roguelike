#include "Game.h"

Game::Game() {}

void Game::start() {
  Window window;

  window.init();
  window.render();
}
