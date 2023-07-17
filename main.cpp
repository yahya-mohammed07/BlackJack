#include "game.hpp"

auto main() -> int {
  Game game{};
  game.createDeck();
  game.shuffleDeck();
  game.printDeck();

  game.play();
  return 0;
}