#include "Profile.h"

namespace player
{

Profile::Profile(const std::string &name)
    : m_name(name)
{
}

void Profile::rename(const std::string &name)
{
    m_name = name;
}

void Profile::add_deck_recipe(const unsigned pos, const DeckRecipe &deck)
{
    m_deck_recipes.emplace(pos, deck);
}

void Profile::add_deck_recipe(const unsigned pos, DeckRecipe &&deck)
{
    m_deck_recipes.emplace(pos, deck);
}

void Profile::remove_deck_recipe(const unsigned pos)
{
    m_deck_recipes.erase(pos);
}

const std::string &Profile::get_name() const
{
    return m_name;
}

const DeckRecipe &Profile::get_deck_recipe(const unsigned pos) const
{
    return m_deck_recipes.at(pos);
}

} // namespace player
