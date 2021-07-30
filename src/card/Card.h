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

    Card(const std::string name, const std::vector<Effect> effects);

    operator std::string() const;

protected:
    const std::string m_name;
    const std::vector<Effect> m_effects;
};

} // namespace card
