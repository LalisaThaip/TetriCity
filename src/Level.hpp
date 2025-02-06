#pragma once

#include <vector>

#include "Block.hpp"

class Level {
 protected:
  std::vector<std::vector<int>> Map;

 public:
  std::vector<Block*> blocks;
  std::vector<std::vector<int>> returnMap();
  std::vector<Block*> returnBlocks();
  ~Level();
};