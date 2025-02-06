#pragma once

#include "Grid.hpp"
#include "Menu.hpp"
#include "Position.hpp"
#include "raylib-cpp.hpp"

void TuteMenu1::Draw(int* Ptr) { //Draws tutorial 1 menu and runs checks for button presses
  pos.x = 0.0;
  pos.y = 0.0;
  this->statePtr = Ptr;
  Vector2 mousePos = {-100.0f, -100.0f};
  mousePos = GetMousePosition();
  BeginDrawing();
    ClearBackground(DARKBLUE);  // Set the background to darkblue
    DrawTextEx(GetFontDefault(), HowTo_text, pos, 20, 1, BLACK);
    DrawRectangle(next_btn.x, next_btn.y, next_btn.width, next_btn.height, GRAY);
    DrawText("Next", width - 140, height - 40, 20, BLACK);
  EndDrawing();
  if (CheckCollisionPointRec(mousePos, next_btn) &&IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) { //if the next button is pressed change window state to 8
    *Ptr = 8;
  }
}

void TuteMenu2::Draw(int* Ptr) {  //Draws tutorial2 menu and runs checks for button presses
  pos.x = 0.0;
  pos.y = 0.0;
  this->statePtr = Ptr;
  Vector2 mousePos = {-100.0f, -100.0f};
  mousePos = GetMousePosition();
  BeginDrawing();
    ClearBackground(DARKBLUE);  // Set the background to darkblue
    DrawTextEx(GetFontDefault(), HowTo_text, pos, 20, 1, BLACK);
    DrawRectangle(next_btn.x, next_btn.y, next_btn.width, next_btn.height, GRAY);
    DrawText("Next", width - 140, height - 40, 20, BLACK);
  EndDrawing();
  if (CheckCollisionPointRec(mousePos, next_btn) &&  IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) { //if the next button is pressed change the window state to 1
    *Ptr = 1;
  }
}
