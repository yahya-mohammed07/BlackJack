#include "lib/game.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

auto main() -> int {
  Game playerALi{};
  playerALi.createDeck();
  playerALi.shuffleDeck();
  playerALi.printDeck();

  std::cout << playerALi.getCardValue(Card{Card::Rank::rank_4, Card::Suit::diamond}) << '\n';

  Game playerYahya{};
  playerYahya.createDeck();
  playerYahya.shuffleDeck();
  playerYahya.printDeck();
}