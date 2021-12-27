#include "Spell.h"

namespace card
{

Spell::Spell(const size_t id, const std::string name, const std::vector<Effect> effects)
    : Card(id, name, effects)
{
}

} // namespace card
