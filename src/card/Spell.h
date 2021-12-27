#pragma once

#include "Unit.h"

namespace card
{

class Spell final : public Card
{
public:
    explicit Spell(const size_t id, const std::string name, const std::vector<Effect> effects);
};

} // namespace card
