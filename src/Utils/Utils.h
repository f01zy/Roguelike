#pragma once

#include <string>

class Utils final {
public:
  Utils();
  int random(int, int);
  int roundToSquare(int);
  std::string readFile(std::string path);
};
