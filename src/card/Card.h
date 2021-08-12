#pragma once

#include "Effect.h"

#include <string>
#include <vector>

namespace card
{

/**
 * \brief Common information of all cards.
 */
class Card
{
public:
    using key_t = std::string;

    explicit Card(const std::string name, const std::vector<Effect> effects);

    operator std::string() const;

protected:
    std::string m_name;
    std::vector<Effect> m_effects;
};

} // namespace card
