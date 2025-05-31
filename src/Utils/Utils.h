#pragma once

#include <string>

class Utils final {
public:
  Utils();
  void sleep(float);
  int random(int, int);
  int roundToSquare(int);
  void clear();
  std::string readFile(std::string path);
};
