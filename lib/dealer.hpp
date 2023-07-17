#ifndef DEALER_HPP
#define DEALER_HPP

class Dealer {
private:
  int m_score{ 0 };
  const int min_point_dealer{ 17 };

public:
  Dealer() {}
  Dealer(const int score) : m_score{ score } {}

  auto getScore() const -> int { return m_score; }
  auto getMinScore() const -> int { return min_point_dealer; }
};

#endif