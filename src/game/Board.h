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
private:
    std::array<std::reference_wrapper<card::Card>, 30U> m_spaces;
};

} // namespace game
