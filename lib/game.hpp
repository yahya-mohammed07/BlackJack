#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include "dealer.hpp"
#include "card.hpp"
#include "rand.hpp"
#include <algorithm>
#include <array>

using Deck = std::array<Card, 52>;
using Index = Deck::size_type;

class Game : public Player, public Dealer {
private:
  Card m_card{};
  Deck m_deck{};
  const int max_score{ 21 };
  const int min_score{ 17 };

public:
  Game() {}

public:

  auto createDeck() -> void {
    int index{ 0 };
    for (int suit{ 0 }; suit < static_cast<int>(Card::Suit::max_suits); ++suit) {
      for (int rank{ 0 }; rank < static_cast<int>(Card::Rank::max_ranks); ++rank) {
        m_deck[index] = Card(static_cast<Card::Rank>(rank),
          static_cast<Card::Suit>(suit));
        ++index;
      }
    }
  }

  auto printDeck() const -> void {
    for (const auto& card : m_deck) {
      std::cout << m_card.printCard(card) << ' ';
    }
    std::cout << '\n';
  }

  auto getCard() const -> Card { return m_deck[Random::get_random(0, 52)]; }

  auto shuffleDeck() -> void {
    std::shuffle(m_deck.begin(), m_deck.end(), Random::mt);
  }

  auto getCardValue(const Card& card) const {
    switch (card.get_rank()) {
    case Card::Rank::rank_ace:
      return 11;
    case Card::Rank::rank_jack: case Card::Rank::rank_queen:
    case Card::Rank::rank_king: case Card::Rank::rank_10:
      return 10;
    default:
      // since enum starts from 0, we add 2 to get the actual value of the card
      return static_cast<int>(card.get_rank()) + 2;
    }
  }

  auto getShuffledDeck() const -> Deck { return m_deck; }

  auto playerTurn(const Deck& shuffleDeck, const Player& player,
    Index cardIndex) -> bool {
    int playerScore{ player.getScore() };
    while (true) {
      if (playerScore > max_score) { // player lost
        return true;
      }
      else {
        if (player.makeChoice() == 'h') { // hit
          playerScore += getCardValue(shuffleDeck[cardIndex++]);
          std::cout << "Your score is: " << playerScore << '\n';
        }
        else { // stand
          return false; // player didn't lose
        }
      }
    }
  }

  auto dealerTurn(const Deck& shuffleDeck, const Dealer& dealer,
    Index cardIndex) -> bool {
    int dealerScore{ dealer.getScore() };
    while (dealerScore < min_score) { // dealer must hit if score is less than 17
      dealerScore += getCardValue(shuffleDeck[cardIndex++]);
      std::cout << "Dealer score is: " << dealerScore << '\n';
    }

    if (dealerScore > max_score) { // dealer lost
      return true; // dealer lost
    }
    return false; // dealer didn't lose
  }

  auto play() -> bool {
    Index cardIndex{ 0 }; // index of the next card to be dealt
    const Dealer dealer{ getCardValue(m_deck[cardIndex++]) }; // first card
    std::cout << "The dealer is showing: " << dealer.getScore() << '\n';
    const Player player{ getCardValue(m_deck[cardIndex]) +
                      getCardValue(m_deck[cardIndex + 1]) }; // first two cards
    std::cout << "You have: " << player.getScore() << '\n';

    cardIndex += 2; // skip the first two cards

    if (playerTurn(m_deck, player, cardIndex)) {
      return false; // player lost
    }
    if (dealerTurn(m_deck, dealer, cardIndex)) {
      return true; // dealer lost
    }
    if (player.getScore() == dealer.getScore()) {
      return false;
    }

    return player.getScore() > dealer.getScore();
  }
};

#endif // GAME_HPP