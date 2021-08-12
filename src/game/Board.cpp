#include "Board.h"

namespace game
{

card::Card *Board::card_at(const std::size_t location) const
{
    return m_spaces.at(location);
}

} // namespace game
