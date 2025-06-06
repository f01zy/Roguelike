#pragma once

#include <chrono>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <random>
#include <string>
#include <thread>

class Utils final {
public:
  Utils();
  void sleep(float);
  int random(int, int);
  int roundToSquare(int);
  void clear();
  std::string readFile(std::string path);
};
