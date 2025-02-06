#include <iostream>
#include <string>

#include "Game.hpp"
#include "Grid.hpp"
#include "Menu.hpp"
#include "Menus.hpp"
#include "raylib-cpp.hpp"


int main() {
  Game game;
  game.Run();

  
  // std::cout << MeasureText("Tutorial", 20) << std::endl <<
  // GetFontDefault().baseSize << std::endl; std::cout <<
  // MeasureText("TetriCity", 20) << std::endl; std::cout << MeasureText("Play",
  // 20) << std::endl;
}