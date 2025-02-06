#include "Grid.hpp"

#include <cstdlib>
#include <iostream>
#include <vector>

#include "Block.hpp"
#include "Blocks.cpp"
#include "Colors.hpp"
#include "Level.hpp"
#include "Levels.hpp"
#include "raylib-cpp.hpp"

Grid::Grid(int i) { //constructor  defining data members (arguement is unimplemented for use to initialize different levels)
  this->gridSize.numRows = 20;
  this->gridSize.numCol = 10;
  this->gridSize.cellSize = 30;
  Initialize(0);
  Colors c;
  colors = c.ReturnColors();
}

Grid::Grid() { //constructor  defining data members
  this->gridSize.numRows = 20;
  this->gridSize.numCol = 10;
  this->gridSize.cellSize = 30;
  Colors c;
  colors = c.ReturnColors();
  Initialize(0);
}

void Grid::Initialize(int i) { 
  lvl = new Level1();
  std::vector<std::vector<int>> mapVec = lvl->returnMap();
  blocks = lvl->returnBlocks(); //defines the grids block list as level1 objects block list
  if (i == 0) {
    for (int row = 0; row < gridSize.numRows; row++) { //iterates through the level1 object's map and defines gridarray as each value
      for (int col = 0; col < gridSize.numCol; col++) {
        gridArray[row][col] = mapVec[row][col];
      }
    }
  }
  // std::cout << "Ran through init" << std::endl;
  this->newBlock();
}

Block* Grid::Get_Block() { return currentBlock; } //getter that returns the current block

bool Grid::IsCellOutside(int row, int column) { //checks if the cell at row and column arguements is outside defined play area
  if (gridArray[row][column] > 0) {
    return true;
  }
  return false;
}

void Grid::Print() { //print the current grid map for testing
  for (int row = 0; row < gridSize.numRows; row++) {
    for (int col = 0; col < gridSize.numCol; col++) {
      std::cout << gridArray[row][col];
    }
    std::cout << std::endl;
  }
}

void Grid::Draw(int* ptr) { //Using raylib drawing every grid array element as a square on program window 
  int cellValue = 0;
  BeginDrawing();
  for (int row = 0; row < gridSize.numRows; row++) {
    for (int col = 0; col < gridSize.numCol; col++) {
      cellValue = gridArray[row][col];
      // Display the each gridcell using display rectangle RAYLIB method
      ClearBackground(DARKGRAY);
      DrawRectangle(col * gridSize.cellSize + 1, row * gridSize.cellSize + 1, gridSize.cellSize - 1, gridSize.cellSize - 1, colors[cellValue]);
      // std::cout << "rectangle Drawn at row:" << row+1 << " And Column:" <<
      // col+1 << std::endl << "Cell value is:" << cellValue << std::endl;
    }
  }
  // drawBox();
  currentBlock->Draw(); //draws current block
  EndDrawing();
}

Grid::~Grid() { //deconstructor deletes current block and all blocklist block objects
  delete currentBlock;
  for (Block* item : blocks) {
    delete item;
  }
}

bool Grid::IsCellPlacable(int row, int column) { //checks if the arguement row and column is placeable
  if (gridArray[row][column] == 1) {  // if val is 1, cell is placeable
    return true;
  } else {
    return false;
  }
}
void Grid::place(std::vector<Position> tiles) { //Change the gridarray values at the arguements tiles
  for (Position items : tiles) {
    gridArray[items.row][items.column] = currentBlock->id;
  }
}

void Grid::newBlock() { //redefine the current block from the blocks vector and deletes the placed block
  if (blocks.size() > 0) {
    int index = rand() % blocks.size();
    Block* block = blocks[index];
    blocks.erase(blocks.begin() + index);
    currentBlock = block;
  } else if (blocks.size() == 0) { //if the vector is empty current block = nullblock
    currentBlock = new nullBlock();
  }
}

std::vector<Block*> Grid::getBlocks() { return blocks; } //return the vector of blocks
