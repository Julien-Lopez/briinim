#pragma once

#include <string>

namespace card
{

enum class Attribute
{
    NORMAL,
    CUNNING,
    FEARLESS,
    SPELLCASTER,
};

inline constexpr const char *s_attribute_cunning_key = "Cunning";
inline constexpr const char *s_attribute_fearless_key = "Fearless";
inline constexpr const char *s_attribute_spellcaster_key = "Spellcaster";

Attribute attribute_from_string(const std::string &s);

} // namespace card
