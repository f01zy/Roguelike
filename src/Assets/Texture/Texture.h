#pragma once

#include <GL/glew.h>
#include <SOIL/SOIL.h>
#include <string>

class Texture final {
public:
  Texture(std::string path, unsigned &texture);
};
