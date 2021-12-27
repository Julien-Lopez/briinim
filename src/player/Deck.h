#pragma once

#include "card/Unit.h"

#include <deque>
#include <memory>
#include <functional>

namespace briinim
{

class CardsDB;

} // namespace briinim

namespace card
{

class Card;

} // namespace card

namespace player
{

class DeckRecipe;

class Deck final
{
public:
    explicit Deck(const std::function<size_t()> card_id_generator, const DeckRecipe &recipe,
        const briinim::CardsDB &cards_db);

    std::unique_ptr<card::Card> pop();

    const card::Unit &get_left_commander() const;
    const card::Unit &get_middle_commander() const;
    const card::Unit &get_right_commander() const;

    void shuffle();

private:
    std::deque<std::unique_ptr<card::Card>> m_cards;
    const std::unique_ptr<card::Unit> m_left_commander;
    const std::unique_ptr<card::Unit> m_middle_commander;
    const std::unique_ptr<card::Unit> m_right_commander;
};

} // namespace player
