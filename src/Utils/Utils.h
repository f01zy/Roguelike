#pragma once

#include <string>

class Utils final {
public:
  Utils();
  int random(int, int);
  std::string readFile(std::string path);
};
