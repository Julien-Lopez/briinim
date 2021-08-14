#include "Card.h"

namespace card
{

Card::Card(const size_t id, const std::string name, const std::vector<Effect> effects)
    : m_id(id),
      m_name(std::move(name)),
      m_effects(std::move(effects))
{
}

size_t Card::get_id() const
{
    return m_id;
}

Card::operator std::string() const
{
    return m_name;
}

} // namespace card
