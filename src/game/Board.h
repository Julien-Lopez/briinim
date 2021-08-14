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
    inline card::Card *operator[](const std::size_t location) const { return m_spaces[location]; }

private:
    std::array<card::Card *, 30U> m_spaces{nullptr};
};

} // namespace game
