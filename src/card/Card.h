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

    explicit Card(const size_t id, const std::string name, const std::vector<Effect> effects);

    size_t get_id() const;

    operator std::string() const;

protected:
    /**
     * \brief The identifier of the card in the game it was created for.
     */
    const size_t m_id;
    std::string m_name;
    std::vector<Effect> m_effects;
};

} // namespace card
