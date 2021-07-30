#include "Deck.h"

namespace player
{

Deck::Deck(const std::string &name)
    : m_name(name)
{
}

void Deck::rename(const std::string &name)
{
    m_name = name;
}

void Deck::add_card(const card::Card::key_t &name)
{
    m_cards[name]++;
}

void Deck::remove_card(const card::Card::key_t &name)
{
    unsigned &nb = m_cards[name];

    if (nb > 1U)
    {
        nb--;
    }
    else
    {
        m_cards.erase(name);
    }
}

} // namespace player
