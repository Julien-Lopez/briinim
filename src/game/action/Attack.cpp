#include "Attack.h"

namespace game
{

Attack::Attack(const card::Card &source, const card::Card &target)
    : m_source(source),
      m_target(target)
{
}

const card::Card &Attack::get_source() const
{
    return m_source;
}

const card::Card &Attack::get_target() const
{
    return m_target;
}

} // namespace game
