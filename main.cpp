#include "lib/game.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

auto main() -> int {
  Game playerALi{};
  playerALi.createDeck();
  playerALi.shuffleDeck();
  playerALi.printDeck();

  Game playerYahya{};
  playerYahya.createDeck();
  playerYahya.shuffleDeck();
  playerYahya.printDeck();
}