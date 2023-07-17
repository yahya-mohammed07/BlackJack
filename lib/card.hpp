#ifndef CARD_HPP
#define CARD_HPP

#include <string>

class Card {
public:
  enum class Suit
  {
    club,
    diamond,
    heart,
    spade,

    max_suits
  };

  enum class Rank
  {
    rank_2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8,
    rank_9,
    rank_10,
    rank_jack,
    rank_queen,
    rank_king,
    rank_ace,

    max_ranks
  };
private:
  Suit m_suit{};
  Rank m_rank{};

public:
  Card() {}
  Card(Rank rank, Suit suit) : m_rank{ rank }, m_suit{ suit } {}

public:
  auto printCard(const Card& cards) const -> std::string {
    std::string res{};
    switch (cards.m_rank)
    {
    case Rank::rank_2: res += "2"; break;
    case Rank::rank_3: res += "3"; break;
    case Rank::rank_4: res += "4";   break;
    case Rank::rank_5: res += "5";  break;
    case Rank::rank_6: res += "6";  break;
    case Rank::rank_7: res += "7";  break;
    case Rank::rank_8: res += "8";  break;
    case Rank::rank_9: res += "9";  break;
    case Rank::rank_10: res += "10";  break;
    case Rank::rank_jack: res += "J"; break;
    case Rank::rank_queen: res += "Q";  break;
    case Rank::rank_king: res += "K"; break;
    case Rank::rank_ace: res += "A";  break;

    default:
      break;
    }

    switch (cards.m_suit)
    {
    case Suit::club: res += "C"; break;
    case Suit::diamond: res += "D"; break;
    case Suit::heart: res += "H"; break;
    case Suit::spade: res += "S"; break;

    default:
      break;

    }
    return res;
  }

  auto get_rank() const { return m_rank; }
};

#endif