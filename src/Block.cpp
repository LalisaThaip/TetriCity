#include "Block.hpp"

#include <iostream>

#include "Blocks.cpp"
#include "Position.hpp"

Block::Block() { //Constructor for Block which defines many of the Block data members
  cellSize = 30;
  rotationState = 0;
  Colors c;
  std::vector<Color> colors = c.ReturnColors();
  rowOffset = 2;
  columnOffset = 2;
}

void Block::Draw() { //Draw function gets the current posiitions of the tiles for the currently controlled block and draws a square where they sit
  std::vector<Position> tiles = getCellPosition();
  // std::cout << "GetCellPos ran" << std::endl;
  for (Position item : tiles) { //Iterates through each tile in the current block
    DrawRectangle(int(item.column * cellSize + 1), int(item.row * cellSize + 1),
                  int(cellSize - 1), int(cellSize - 1), PURPLE);
  }
}

void Block::Move(int rows, int columns) { //Increases the block position by the function arguments
  // std::cout << "RowOffset before: " << rowOffset << "ColumnOffset before: "
  // << columnOffset << std::endl;
  rowOffset += rows;
  columnOffset += columns;
  // std::cout << "RowOffset after: " << rowOffset << "ColumnOffset after: " <<
  // columnOffset << std::endl;
}

std::vector<Position> Block::getCellPosition() { //Returns the tiles which the block inhabits for its given rotation state
  // std::cout << "Get cell started" << std::endl;
  std::vector<Position> tiles = cells[rotationState];
  // std::cout << "Tiles obtained" << std::endl;
  std::vector<Position> movedTiles;
  for (Position item : tiles) { //iterates throug tiles block inhabits and returns its position
    Position newPos(int(item.row + rowOffset), int(item.column + columnOffset));
    movedTiles.push_back(newPos);
    // std::cout << "Pushed to movedtiles" << std::endl;
  }
  return movedTiles;
}

void Block::Rotate(int i) { //Rotate method changes the rotation state of the block depending on argument (0=clockwise, 1=anticlockwise)
  if (i == 0) {
    rotationState++;
    if (rotationState == cells.size()) {
      rotationState = 0;
    }
  } else if (i == 1) {
    rotationState--;
    if (rotationState < 0) {
      rotationState = cells.size();
    }
  }
}