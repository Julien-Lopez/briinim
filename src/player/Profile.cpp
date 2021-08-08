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

void Profile::add_deck(const unsigned pos, const Deck &deck)
{
    m_decks.emplace(pos, deck);
}

void Profile::add_deck(const unsigned pos, Deck &&deck)
{
    m_decks.emplace(pos, deck);
}

void Profile::remove_deck(const unsigned pos)
{
    m_decks.erase(pos);
}

const std::string &Profile::get_name() const
{
    return m_name;
}

const Deck &Profile::get_deck(const unsigned pos) const
{
    return m_decks.at(pos);
}

} // namespace player
