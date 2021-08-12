#include "DeckRecipe.h"

namespace player
{

DeckRecipe::DeckRecipe(const std::string &name)
    : m_name(name)
{
}

void DeckRecipe::rename(const std::string &name)
{
    m_name = name;
}

std::unordered_map<card::Card::key_t, unsigned> DeckRecipe::get_cards() const
{
    return m_cards;
}

void DeckRecipe::add_card(const card::Card::key_t &key)
{
    m_cards[key]++;
}

void DeckRecipe::remove_card(const card::Card::key_t &key)
{
    unsigned &nb = m_cards[key];

    if (nb > 1U)
    {
        nb--;
    }
    else
    {
        m_cards.erase(key);
    }
}

const card::Card::key_t &DeckRecipe::get_left_commander() const
{
    return m_left_commander;
}

void DeckRecipe::set_left_commander(const card::Card::key_t &key)
{
    m_left_commander = key;
}

const card::Card::key_t &DeckRecipe::get_middle_commander() const
{
    return m_middle_commander;
}

void DeckRecipe::set_middle_commander(const card::Card::key_t &key)
{
    m_middle_commander = key;
}

const card::Card::key_t &DeckRecipe::get_right_commander() const
{
    return m_right_commander;
}

void DeckRecipe::set_right_commander(const card::Card::key_t &key)
{
    m_right_commander = key;
}

} // namespace player
