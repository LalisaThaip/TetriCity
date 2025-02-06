#include "Menu.hpp"
#include "Menus.hpp"
#include "Position.hpp"
#include "raylib-cpp.hpp"

void StartMenu::Draw(int *Ptr) { //Draws Start menu and runs checks for button presses
  this->statePtr = Ptr;
  Vector2 mousePos = {-100.0f, -100.0f};
  mousePos = GetMousePosition();
  BeginDrawing();
    ClearBackground(DARKBLUE);  // Set the background to darkblue
    DrawText("Select Level", Label.column, Label.row, 20, BLACK);
    DrawRectangle(lvl1_btn.x, lvl1_btn.y, lvl1_btn.width, lvl1_btn.height, RED);
    DrawText("Level 1", lvl1_text.column, lvl1_text.row, 20, BLACK);
    DrawRectangle(lvl2_btn.x, lvl2_btn.y, lvl2_btn.width, lvl2_btn.height, RED);
    DrawText("Back", lvl2_text.column, lvl2_text.row, 20, BLACK);
  EndDrawing();

  //If mouse button is pressed and mouse rectangle is collidign with buttons call button method
  if (CheckCollisionPointRec(mousePos, lvl1_btn) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    lvl1_btn_pressed();
  } else if (CheckCollisionPointRec(mousePos, lvl2_btn) &&IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    lvl2_btn_pressed();
  }
}

void StartMenu::lvl1_btn_pressed() { *statePtr = 2; } //change window state to 2

void StartMenu::lvl2_btn_pressed() { *statePtr = 1; } //change window state to 1