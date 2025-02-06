#include "Level.hpp"

#include <vector>

#include "Block.hpp"

std::vector<std::vector<int>> Level::returnMap() { return this->Map; } //return the level's map

std::vector<Block*> Level::returnBlocks() { return blocks; } //return the level's blocks

Level::~Level() { //deconstuctor deletes all level blocks 
  for (Block* items : blocks) {
    delete items;
  }
}