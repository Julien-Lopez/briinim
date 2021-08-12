#pragma once

#include <array>

namespace card
{

class Card;

} // namespace card

namespace game
{

class Board final
{
public:
    card::Card *card_at(const std::size_t location) const;

private:
    std::array<card::Card *, 30U> m_spaces;
};

} // namespace game
