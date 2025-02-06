#pragma once
#include <map>
#include <vector>

#include "Colors.hpp"
#include "Position.hpp"

class Block {
 protected:
  int cellSize;
  int rotationState;
  int rowOffset;
  int columnOffset;
  std::vector<Color> colors;

 public:
  Block();
  int id;
  std::map<int, std::vector<Position>> cells;
  void Draw();
  void Move(int, int);
  std::vector<Position> getCellPosition();
  void Rotate(int i);
};
