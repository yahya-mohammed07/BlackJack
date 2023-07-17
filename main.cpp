#include "lib/game.hpp"

auto main() -> int {
  Game game{};
  game.createDeck(); // create a deck of cards
  game.shuffleDeck(); // shuffle the deck of cards
  if(game.play()) { // play the game
    std::cout << "You won!\n";
  } else {
    std::cout << "You lost!\n";
  }
}