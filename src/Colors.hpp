#pragma once
#include <raylib.hpp>
#include <vector>

class Colors {
 private:
  Color darkGrey;
  Color green;
  Color red;
  Color orange;
  Color yellow;
  Color purple;
  Color cyan;
  Color blue;

 public:
  Colors();
  std::vector<Color> ReturnColors();
};
