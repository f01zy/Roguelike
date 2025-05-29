#include "Utils.h"
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <random>
#include <thread>

Utils::Utils() {}

void Utils::sleep(float seconds) {
  int milliseconds = seconds * 1000;
  std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

int Utils::random(int min, int max) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution dist(min, max);

  return dist(gen);
}

int Utils::roundToSquare(int rooms) {
  int root = std::ceil(std::sqrt(rooms));
  return root * root;
}

void Utils::clear() {
  // ...
  system("clear");
}
