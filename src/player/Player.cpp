#include "Player.h"

#include "Profile.h"

namespace player
{

Player::Player(const Profile &profile, const unsigned deck_number)
    : m_profile(profile),
      m_deck(profile.get_deck(deck_number))
{
}

const std::string &Player::get_name() const
{
    return m_profile.get_name();
}

} // namespace player
