#include "Move.h"

namespace game
{

Move::Move(const card::Card &target, const std::size_t new_position)
    : m_target(target),
      m_new_position(new_position)
{
}

const card::Card &Move::get_target() const
{
    return m_target;
}

std::size_t Move::get_new_position() const
{
    return m_new_position;
}

} // namespace game
