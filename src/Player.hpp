#pragma once

#include <iostream>
#include <string>

class Player {
 private:
  std::string name;
  int score;

 public:
  Player();
  Player(const std::string& playerName);
  void incrementScore(int points);
  int getScore();
};
