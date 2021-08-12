#pragma once

#include "DeckRecipe.h"

#include <string>
#include <unordered_map>

namespace player
{

class Profile final
{
public:
    explicit Profile(const std::string &name);

    void rename(const std::string &name);
    void add_deck_recipe(const unsigned pos, const DeckRecipe &deck);
    void add_deck_recipe(const unsigned pos, DeckRecipe &&deck);
    void remove_deck_recipe(const unsigned pos);

    const std::string &get_name() const;
    const DeckRecipe &get_deck_recipe(const unsigned pos) const;

private:
    std::string m_name;
    std::unordered_map<unsigned, DeckRecipe> m_deck_recipes;
};

} // namespace player
