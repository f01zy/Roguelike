#include "Utils.h"
#include <chrono>
#include <thread>

Utils::Utils() {}

void Utils::sleep(float seconds) {
  int milliseconds = static_cast<int>(seconds * 1000);
  std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
