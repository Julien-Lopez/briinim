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
    inline const card::Card * const &operator[](const std::size_t location) const { return m_spaces[location]; }
    inline const card::Card * &operator[](const std::size_t location) { return m_spaces[location]; }

private:
    std::array<const card::Card *, 30U> m_spaces{nullptr};
};

} // namespace game
