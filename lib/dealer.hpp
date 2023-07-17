#ifndef DEALER_HPP
#define DEALER_HPP

class Dealer {
private:
  int m_score{ 0 };

public:
  Dealer() {}
  Dealer(const int score) : m_score{ score } {}

  auto getScore() const -> int { return m_score; }
};

#endif