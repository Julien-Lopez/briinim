#include "Unit.h"

namespace card
{

Unit::Unit(const size_t game_id, const std::string name, const std::vector<Effect> effects, const unsigned rank,
    const std::vector<Species> species, const std::vector<Attribute> attributes, const unsigned atk,
    const unsigned range, const unsigned movement, const unsigned max_hp)
    : Card(std::move(game_id), std::move(name), std::move(effects)),
      m_species(std::move(species)),
      m_attributes(std::move(attributes)),
      m_rank(std::move(rank)),
      m_atk(std::move(atk)),
      m_range(std::move(range)),
      m_movement(std::move(movement)),
      m_max_hp(std::move(max_hp)),
      m_hp(m_max_hp)
{
}

} // namespace card
