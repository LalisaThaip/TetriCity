#pragma once

#include "raylib-cpp.hpp"

class Menu {
 protected:
  int width = 300;
  int height = 600;
  int* statePtr;

 public:
  void Draw(int*);
};
