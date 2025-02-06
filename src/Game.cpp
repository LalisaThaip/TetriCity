#include "Game.hpp"

#include <unistd.h>
#include <fstream>
#include <iostream>
#include <string>

#include "Blocks.cpp"
#include "GameSound.hpp"
#include "Grid.hpp"
#include "Menu.hpp"
#include "Menus.hpp"
#include "Player.hpp"
#include "StartMenu.cpp"
#include "TuteMenus.cpp"
#include "Window.hpp"
#include "raylib-cpp.hpp"

Game::Game() { //Game constructor defines all the data members for Game including instantiating classes for the needed game objects
  this->_width = 500;
  this->_height = 600;
  this->_title = "TetriCity";
  this->_windowState = 1;
  this->_soundLocation = "resources/sound.wav";
  this->_statePtr = &_windowState;
  _menu = new MainMenu();
  _grid = new Grid();
  _player = new Player();
  start_menu = new StartMenu();
  Tute_menu1 = new TuteMenu1();
  Tute_menu2 = new TuteMenu2();
}

void Game::Run() { //Run method is called in main and defines the main loop for the game window
  InitWindow(
      _width, _height,
      _title);  // Initialize window with width, height and title members.
  InitAudioDevice();
  GameSound background(0.2, _soundLocation);
  background.Play();
  SetTargetFPS(60);

  while (!WindowShouldClose()) { //When no button to close the window is pressed continue with loop
    switch (this->_windowState) { //Depending on the window state different menu's will be called including: Grid, Menu, Tute__menu, start_menu and main menu
      case 1:
        this->_menu->Draw(_statePtr);
        break;
      case 2: //when in the main game window handle input's and draw the score and grid
        Input();
        drawScore(_player);
        this->_grid->Draw(_statePtr);
        break;
      case 3:
        this->start_menu->Draw(_statePtr);
        break;
      case 4:
        this->Tute_menu1->Draw(_statePtr);
        break;
      case 8:
        this->Tute_menu2->Draw(_statePtr);
        break;
      default: //If a nondefined state is chosen boot into a 
        BeginDrawing();
        DrawText("No State", 150, 300, 20, BLACK);
        EndDrawing();
        break;
    }
  }
  CloseWindow();
}

void Game::changeState(int i) { this->_windowState = i; } //setter for the window state

void Game::Input() { //Find the pressed key and depending on the input call corresponding method
  int keyPressed = GetKeyPressed();
  switch (keyPressed) {
    case KEY_UP:
      MoveBlock(0);
      break;
    case KEY_DOWN:
      MoveBlock(1);
      break;
    case KEY_LEFT:
      MoveBlock(2);
      break;
    case KEY_RIGHT:
      MoveBlock(3);
      break;
    case KEY_R:
      rotateBlock(0);
      break;
    case KEY_T:
      rotateBlock(1);
      break;
    case KEY_ENTER:
      if (isBlockPlaceable()) {
        placeBlock();
        _grid->newBlock();
      }
      break;
  }
}

void Game::MoveBlock(int direction)  // Direction corresponds to up(0), down(1), left(2) and right(3)
{
  currentBlock = getCurrentBlock();
  switch (direction) {
    case 0:
      currentBlock->Move(-1, 0);
      if (isBlockOutside()) {
        currentBlock->Move(1, 0);
      }
      break;
    case 1:
      currentBlock->Move(1, 0);
      if (isBlockOutside()) {
        currentBlock->Move(-1, 0);
      }
      break;
    case 2:
      currentBlock->Move(0, -1);
      if (isBlockOutside()) {
        currentBlock->Move(0, 1);
      }
      break;
    case 3:
      currentBlock->Move(0, 1);
      if (isBlockOutside()) {
        currentBlock->Move(0, -1);
      }
      break;
  }
}

void Game::rotateBlock(int i) { //Rotate block (0=clockwise, 1=anticlockwise)
  switch (i) {
    case 0:
      currentBlock->Rotate(0);
      if (isBlockOutside()) {
        currentBlock->Rotate(1);
      }
      break;
    case 1:
      currentBlock->Rotate(1);
      if (isBlockOutside()) {
        currentBlock->Rotate(0);
      }
      break;
  }
}

bool Game::isBlockPlaceable() {  // calls is cell outside for each tile of a block
  std::vector<Position> tiles = currentBlock->getCellPosition();
  for (Position item :tiles) {  // for all the tiles in the block if tile enters a grid with val 0 it returns false
    if (!_grid->IsCellPlacable(item.row, item.column)) {
      drawError(); // Error message is displayed
      return false;
    }
  }
  return true;
}

Block* Game::getCurrentBlock() { return _grid->Get_Block(); } //return the currently selected block

bool Game::isBlockOutside() { //Check if any of the blocks tiles are outside the defined grid
  std::vector<Position> tiles = currentBlock->getCellPosition();
  for (Position item : tiles) {
    if (!_grid->IsCellOutside(item.row, item.column)) {
      return true;
    }
  }
  return false;
}

Game::~Game() { //deconstructor which deletes all instanciated class objects which are defined dynamically
  delete _menu;
  delete _grid;
  delete _player;
  delete start_menu;
  delete Tute_menu1;
  delete Tute_menu2;
}

void Game::placeBlock() { //Draw grid's place for all the block tiles
  std::vector<Position> tiles = currentBlock->getCellPosition();
  _grid->place(tiles);
  for (Position item : tiles) { //increment the score for each tile placed
    _player->incrementScore(1);
  }
}

void Game::drawScore(
    Player*_player) {  // Draws the score dynamically for each change in the score and draw/checkfor press of save_btn and load_btn
  Vector2 mousePos = {-100.0f, -100.0f};
  Rectangle save_btn = {float(this->_width - 180),
                        float(this->_height / 2.0f - 20.0f), (float)170,
                        (float)40};
  Rectangle load_btn = {float(this->_width - 180),
                        float(this->_height / 2.0f + 30), (float)170,
                        (float)40};
  mousePos = GetMousePosition();
  int score =_player->getScore();  // score updates after a block is placed from input
  // Score visuals

  DrawText("Score", 350, 10, 20, WHITE);

  char scoreText[10];

  snprintf(scoreText, sizeof(scoreText), "%d", score);
  Vector2 textsize = MeasureTextEx(GetFontDefault(), scoreText, 38, 2);
  // left ,width, right, height
  DrawRectangle(save_btn.x, save_btn.y, save_btn.width, save_btn.height, BLUE);
  DrawRectangle(load_btn.x, load_btn.y, load_btn.width, load_btn.height, BLUE);
  DrawText("Save", save_btn.x + 10, save_btn.y + 10, 20, BLACK);
  DrawText("Load", load_btn.x + 10, load_btn.y + 10, 20, BLACK);
  DrawRectangleRounded({320, 50, 170, 100}, 0.3, 6,BLUE);  // Draw the blue box behind score number
  DrawTextEx(GetFontDefault(), scoreText, {380, 75}, 38, 2, WHITE);  // Draws number score and updates

  /*
  If the mouse button is clicked while the mouse rectangle is colliding with button rectangle call the defined method (save or load)
  */
  if (CheckCollisionPointRec(mousePos, save_btn) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    save();
  } else if (CheckCollisionPointRec(mousePos, load_btn) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    load();
  }
}

void Game::drawError() { //display text "Cant Place Block here" on screen and wait one second
  BeginDrawing();
  ClearBackground(DARKGRAY);
  DrawText("Can't place block here", _width / 2 - 100, _width / 2 - 100, 20,
           BLACK);
  EndDrawing();
  sleep(1);
}

/*
Save the current map at time of save button click to map_file and save the remaining blocks in the block list into block_file
*/
void Game::save() { 
  std::vector<Block*> blocks;
  blocks = _grid->getBlocks();
  std::ofstream map_file("resources/map.txt");
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++) {
      map_file << _grid->gridArray[i][j] << " ";
    }
    map_file << '\n';
  }
  map_file.close();
  std::ofstream block_file("resources/blocks.txt");
  block_file << blocks.size() + 1 << "\n"; //defines the amount of times needed to iterate when loading
  block_file << _grid->Get_Block()->id << " ";
  if (blocks.size() != 0) {
    for (int i = 0; i < blocks.size(); i++) {
      block_file << blocks[i]->id << " ";
    }
  }
  block_file.close();
}

/*
Reads from files and obtains the contained integers 
*/
void Game::load() { 
  std::vector<int> tempid;
  std::vector<Block*> tempBlock;
  int tempgrid[20][10];
  std::ifstream map_file("resources/map.txt");
  for (int i = 0; i < 20; i++) { //For every integer contained in the map_file (seperated by whitespace) define tempgrid at indexes i and j
    for (int j = 0; j < 10; j++) {
      map_file >> tempgrid[i][j];
      // std::cout << tempgrid[i][j];
    }
    // std::cout << "\n";
  }
  map_file.close();
  for (int i = 0; i < 20; i++) { //Iterate through the temp array and redefines the gridArray for tempgrid integers
    for (int j = 0; j < 10; j++) {
      _grid->gridArray[i][j] = tempgrid[i][j];
    }
  }
  std::ifstream block_file("resources/blocks.txt");
  int count;
  block_file >> count;
  std::cout << count << "\n";
  for (int i = 0; i < count; i++) { //For the defined count (int representing vector size) iterate through the file and push to the back of tempid vector
    int id;
    block_file >> id;
    tempid.push_back(id);
    std::cout << tempid[i] << " ";
  }
  block_file.close();
  for (int id : tempid) { //For every id in the tempid vector instantiate a new block and push to tempblock
    switch (id) {
      case 2:
        tempBlock.push_back(new CBlock());
        break;
      case 3:
        tempBlock.push_back(new IBlock());
        break;
      case 4:
        tempBlock.push_back(new LBlock());
        break;
      case 5:
        tempBlock.push_back(new SBlock());
        break;
      case 6:
        tempBlock.push_back(new TBlock());
        break;
      case 7:
        tempBlock.push_back(new JBlock());
        break;
      case 8:
        tempBlock.push_back(new OBlock());
        break;
      case 9:
        tempBlock.push_back(new ZBlock());
        break;
    }
  }
  _grid->getBlocks() = tempBlock; //redefine the grid blocks 
  _grid->newBlock(); //redefine current block
}

/*
bool collisionDetection(int newRowOffset, int newColOffset){
  std::vector<Position> currentTiles = currentBlock->getCellPosition();
  for (Position item: currentTiles){int newRow = item.row + newRowOffset;
  int newCol = item.
}
*/