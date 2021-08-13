#include "Call.h"

namespace game
{

Call::Call(const card::Card &target, const std::size_t initial_position)
    : m_target(target),
      m_initial_position(initial_position)
{
}

const card::Card &Call::get_target() const
{
    return m_target;
}

std::size_t Call::get_initial_position() const
{
    return m_initial_position;
}

} // namespace game
