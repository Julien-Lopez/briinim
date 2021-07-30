#include "Attribute.h"

namespace card
{

Attribute attribute_from_string(const std::string &s)
{
    return s == s_attribute_cunning_key ? Attribute::CUNNING
        : s == s_attribute_fearless_key ? Attribute::FEARLESS
        : s == s_attribute_spellcaster_key ? Attribute::SPELLCASTER
        : Attribute::NORMAL;
}

} // namespace card
