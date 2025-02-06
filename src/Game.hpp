#pragma once

#include <iostream>
#include <string>

#include "Block.hpp"
#include "Grid.hpp"
#include "Menu.hpp"
#include "Menus.hpp"
#include "Player.hpp"
#include "raylib-cpp.hpp"

class Game {
 private:
  int _width;
  int _height;
  const char *_title;
  const char *_soundLocation;
  int _windowState;
  int *_statePtr;
  Block *currentBlock;
  Grid *_grid;
  MainMenu *_menu;
  Player *_player;
  StartMenu *start_menu;
  TuteMenu1 *Tute_menu1;
  TuteMenu2 *Tute_menu2;

 public:
  Game();
  void Run();  // method which desplays the Game/window
  void changeState(int);
  void Input();
  void MoveBlock(int);
  void rotateBlock(int);
  void placeBlock();
  Block *getCurrentBlock();
  bool isBlockOutside();
  bool isBlockPlaceable();
  void drawScore(Player *player);
  void drawError();
  bool collisionDetection();
  void save();
  void load();
  ~Game();
};