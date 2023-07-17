#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

class Player {
private:
  int m_score{ 0 };

public:
  Player() {}
  Player(const int score) : m_score{ score } {}

public:
  auto getScore() const -> int { return m_score; }
  auto makeChoice() const -> char {
    while (true) { // loop until valid input
      char temp{};
      std::cout << "Do you want to hit or stand? (h/s): ";
      std::cin >> temp;
      return temp;
    }
  }
};

#endif