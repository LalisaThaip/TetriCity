#include <iostream>

#include "Grid.hpp"
#include "Menus.hpp"

MainMenu::MainMenu() {
  this->width = 300;
  this->height = 600;
  this->title = "TetriCity";
}

void MainMenu::Draw(int *ptr) { //draws the main menu and runs checks if either button has been pressed
  Vector2 mousePos = {-100.0f, -100.0f};
  Rectangle start_btn = {(this->width / 2.0f - 41.0f),(this->height / 2.0f - 20.0f), (float)100, (float)40};
  Rectangle Tute_btn = {(this->width / 2.0f - 41.0f),(this->height / 2.0f + 40), (float)100, (float)40};
  mousePos = GetMousePosition();

  BeginDrawing();
    ClearBackground(DARKBLUE);  // Set the background to darkblue
    DrawFPS(10, 10);
    DrawRectangle(start_btn.x, start_btn.y, start_btn.width, start_btn.height,GRAY);
    DrawText("Play", 140, 290, 20, BLACK);
    DrawText("TetriCity", 108, 100, 20, BLACK);
    DrawRectangle(Tute_btn.x, Tute_btn.y, Tute_btn.width, Tute_btn.height, GRAY);
    DrawText("Tutorial", width / 2 - 82 / 2, height / 2 + 50, 20, BLACK);
  // DrawText("TetriCity", 190, 200, 20, LIGHTGRAY);
  EndDrawing();


  //if the buttons have been pressed call respective method
  if (CheckCollisionPointRec(mousePos, start_btn) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    StartPressed(ptr);
  } else if (CheckCollisionPointRec(mousePos, Tute_btn) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    TutePressed(ptr);
  }
}

/*
Change window state depending on button press 
*/
void MainMenu::StartPressed(int *ptr) { *ptr = 3; }
void MainMenu::TutePressed(int *ptr) { *ptr = 4; }