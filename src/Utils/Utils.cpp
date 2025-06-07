#include "Utils.h"
#include <cmath>
#include <fstream>
#include <random>

Utils::Utils() {}

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

std::string Utils::readFile(std::string path) {
  std::ifstream file(path);
  return {std::istreambuf_iterator<char>(file), {}};
}
