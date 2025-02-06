#include "Colors.hpp"

Colors::Colors() { //constructor defines the colours in color class
  darkGrey = {26, 31, 40, 255};
  green = {47, 230, 23, 255};
  red = {232, 18, 18, 255};
  orange = {226, 116, 17, 255};
  yellow = {237, 234, 4, 255};
  purple = {166, 0, 247, 255};
  cyan = {21, 204, 209, 255};
  blue = {13, 64, 216, 255};
}

std::vector<Color> Colors::ReturnColors() { //return a vector of raylib colours
  return {darkGrey, LIGHTGRAY, red,    orange, yellow, purple,
          cyan,     blue,      ORANGE, GREEN,  PINK};
}