#pragma once

#include <string>

#include "Grid.hpp"
#include "Menu.hpp"
#include "Position.hpp"
#include "raylib-cpp.hpp"


/*
Menus.hpp defines all the new Menu classes and their required attributes 
*/
class StartMenu : public Menu {
 private:
  Position Label = {height / 2 - 100, width / 2 - 65};
  Rectangle lvl1_btn = {float(width / 2.0f - 50.0f), height / 2.0f - 15.0f, 100.0f, 30.0f};
  Position lvl1_text = {height / 2 - 10, width / 2 - 33};
  Rectangle lvl2_btn = {float(width / 2.0f - 50.0f), float(height / 2.0f - 15.0f + 90.0f), 100.0f, 30.0f};
  Position lvl2_text = {height / 2 + 80, width / 2 - 36};

 public:
  void Draw(int* statePtr);
  void lvl1_btn_pressed();
  void lvl2_btn_pressed();
};

class MainMenu : public Menu {
 private:
  const char* title;

 public:
  MainMenu();
  void Draw(int*);  // method which desplays the menu/window
  void StartPressed(int*);
  void TutePressed(int*);
};

class TuteMenu1 : public Menu {
 private:
  const char* HowTo_text =
      "When in a level use the arrow\nkeys to move the current \nblock. When "
      "the desired spot \nto  place the block is found \npress enter to "
      "permanentlly \nplace the block";

 protected:
  Vector2 pos;
  Rectangle next_btn = {float(width - 150.0f), float(height - 50.0f), 100.0f,
                        30.0f};

 public:
  virtual void Draw(int* Ptr);
};

class TuteMenu2 : public TuteMenu1 {
 private:
  const char* HowTo_text =
      "When placing blocks you \nwill get points and when\nall blocks have "
      "been placed \nthe level is won.";

 public:
  void Draw(int* Ptr);
};
