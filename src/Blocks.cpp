#include <map>
#include <vector>

#include "Block.hpp"
#include "Colors.hpp"
#include "Position.hpp"

/*
Blocks class defines the different types of blocks inherited from the block interface
Constructors for every block defines the tiles it inhabits at each rotation state and the block ID used for the colour when placed
*/

class CBlock : public Block {
 public:
  CBlock() {
    id = 2;
    cells[0] = {Position(0, 0), Position(0, 2), Position(1, 0), Position(1, 1),
                Position(1, 2)};
    cells[1] = {Position(0, 2), Position(0, 1), Position(1, 1), Position(2, 1),
                Position(2, 2)};
    cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0),
                Position(2, 2)};
    cells[3] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 0),
                Position(2, 1)};
  }
};

class IBlock : public Block {
 public:
  IBlock() {
    id = 3;
    cells[0] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)};
    cells[1] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)};
    cells[2] = {Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)};
    cells[3] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)};
  }
};

class LBlock : public Block {
 public:
  LBlock() {
    id = 4;
    cells[0] = {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)};
    cells[1] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)};
    cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)};
    cells[3] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)};
  }
};

class SBlock : public Block {
 public:
  SBlock() {
    id = 5;
    cells[0] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)};
    cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)};
    cells[2] = {Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1)};
    cells[3] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)};
  }
};

class TBlock : public Block {
 public:
  TBlock() {
    id = 6;
    cells[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)};
    cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)};
    cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)};
    cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};
  }
};

class JBlock : public Block {
 public:
  JBlock() {
    id = 7;
    cells[0] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)};
    cells[1] = {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)};
    cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)};
    cells[3] = {Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1)};
  }
};

class OBlock : public Block {
 public:
  OBlock() {
    id = 8;
    cells[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
  };
};

class ZBlock : public Block {
 public:
  ZBlock() {
    id = 9;
    cells[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
    cells[1] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)};
    cells[2] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)};
    cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)};
  }
};

class nullBlock : public Block { //Nullblock is call for the current block when the levels block list is empty to prevent seg fault
 public:
  nullBlock() {
    id = 0;
    cells[0] = {};
  }
};