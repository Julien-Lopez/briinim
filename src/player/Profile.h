#pragma once

#include "Deck.h"

#include <string>
#include <unordered_map>

namespace player
{

class Profile
{
public:
    explicit Profile(const std::string &name);

    void rename(const std::string &name);
    void add_deck(const unsigned pos, const Deck &deck);
    void add_deck(const unsigned pos, Deck &&deck);
    void remove_deck(const unsigned pos);

    const std::string &get_name() const;
    const Deck &get_deck(const unsigned pos) const;

private:
    std::string m_name;
    std::unordered_map<unsigned, Deck> m_decks;
};

} // namespace player
