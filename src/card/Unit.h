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
    Unit(const std::string name, const std::vector<Effect> effects, const size_t rank,
        const std::vector<Species> species, const std::vector<Attribute> attributes, const size_t atk,
        const size_t range, const size_t movement, const size_t hp);

private:
    const size_t m_rank;
    const std::vector<Species> m_species;
    const std::vector<Attribute> m_attributes;
    const size_t m_atk;
    const size_t m_range;
    const size_t m_movement;
    const size_t m_hp;
};

} // namespace card
