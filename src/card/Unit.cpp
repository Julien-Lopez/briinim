#include "Unit.h"

namespace card
{

Unit::Unit(const std::string name, const std::vector<Effect> effects, const size_t rank,
    const std::vector<Species> species, const std::vector<Attribute> attributes, const size_t atk, const size_t range,
    const size_t movement, const size_t hp)
    : Card(std::move(name), std::move(effects)),
      m_rank(std::move(rank)),
      m_species(std::move(species)),
      m_attributes(std::move(attributes)),
      m_atk(std::move(atk)),
      m_range(std::move(range)),
      m_movement(std::move(movement)),
      m_hp(std::move(hp))
{
}

} // namespace card
