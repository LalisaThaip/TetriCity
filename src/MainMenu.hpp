#pragma once
#include "raylib.hpp"

class MainMenu {
 private:
  int width;
  int height;
  const char* title;

 public:
  MainMenu();
  void Draw(int*);  // method which desplays the menu/window
  void ButtonPressed(int*);
};