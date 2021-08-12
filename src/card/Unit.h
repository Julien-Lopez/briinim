#pragma once

#include "Card.h"
#include "Species.h"
#include "Attribute.h"

#include <vector>

namespace card
{

class Unit final : public Card
{
public:
    Unit(const std::string name, const std::vector<Effect> effects, const unsigned rank,
        const std::vector<Species> species, const std::vector<Attribute> attributes, const unsigned atk,
        const unsigned range, const unsigned movement, const unsigned max_hp);

    inline bool is_dead() const { return m_hp < 1; }

private:
    const std::vector<Species> m_species;
    const std::vector<Attribute> m_attributes;
    const unsigned m_rank;
    const unsigned m_atk;
    const unsigned m_range;
    const unsigned m_movement;
    const unsigned m_max_hp;
    const unsigned m_hp;
};

} // namespace card
