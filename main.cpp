#include "lib/game.hpp"

auto main() -> int {
  Game game{};
  game.createDeck(); // create a deck of cards
  game.shuffleDeck(); // shuffle the deck of cards
  game.play(); // play the game
}