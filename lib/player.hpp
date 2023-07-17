#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

class Player {
private:
  int m_score{ 0 };
  const int max_player_limit{ 21 };

public:
  Player() {}
  Player(const int score) : m_score{ score } {}

public:
  auto getScore() const -> int { return m_score; }
  auto getMaxScore() const -> int { return max_player_limit; }
  auto makeChoice() const -> char {
    char temp{};
    std::cout << "Do you want to hit or stand? (h/s): ";
    std::cin >> temp;
    return temp;
  }
};

#endif