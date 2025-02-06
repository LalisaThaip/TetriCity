#include "Player.hpp"

#include <cstdlib>
#include <iostream>
#include <vector>

#include "raylib-cpp.hpp"

/*Player::Player(const std::string& playerName) {
    this -> name = playerName;
    this -> score = 0;
}*/

Player::Player() { //Player constructor defines name and score
  this->name = "";
  this->score = 0;
}

void Player::incrementScore(int points) { //increments score member by argument
  this->score += points;
  std::cout << name << "'s score: " << score << std::endl;
}

int Player::getScore() { return this->score; } //returns score member