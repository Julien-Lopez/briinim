#include "Player.h"

namespace player
{

Player::Player(const std::string &name)
    : m_name(name)
{
}

void Player::rename(const std::string &name)
{
    m_name = name;
}

void Player::add_deck(const unsigned pos, const Deck &deck)
{
    m_decks.emplace(pos, deck);
}

void Player::add_deck(const unsigned pos, Deck &&deck)
{
    m_decks.emplace(pos, deck);
}

void Player::remove_deck(const unsigned pos)
{
    m_decks.erase(pos);
}

} // namespace player
