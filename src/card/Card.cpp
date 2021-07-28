#include "Card.h"

namespace card
{

Card::Card(const std::string name, const std::vector<Effect> effects)
    : m_name(std::move(name)),
      m_effects(std::move(effects))
{
}

Card::operator std::string() const
{
    return m_name;
}

} // namespace card
