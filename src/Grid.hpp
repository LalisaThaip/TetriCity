#pragma once

#include <vector>

#include "Block.hpp"
#include "Colors.hpp"
#include "Grid.hpp"
#include "Level.hpp"
#include "Menus.hpp"
#include "raylib-cpp.hpp"

struct _gridSize {
  int numRows;   // Number of rows
  int numCol;    // Number of Columns
  int cellSize;  // Size of cells/tiles in pixels
};

class Grid {
 private:
  _gridSize gridSize;
  std::vector<Color>
      colors;  // Vector of colours which is instanciated by GetColor method.
  Block* currentBlock;
  std::vector<Block*> placed;
  std::vector<Block*> blocks;
  Level* lvl;

 public:
  int gridArray[20][10];  // Multilevel array of integers representing the map.
                          // array[row][column]
  Grid();
  Grid(int);
  void Draw(int*);       // Method which displays the grid
  void Print();          // Print method for testing
  void Initialize(int);  // Method which initializes all data members along with
                         // Grid constructor
  Block* Get_Block();
  void newBlock();
  void place(std::vector<Position> tiles);
  bool IsCellOutside(int row, int column);
  bool IsCellPlacable(int row, int column);
  std::vector<Block*> getBlocks();
  ~Grid();
};