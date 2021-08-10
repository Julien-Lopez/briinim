#include "Player.h"

#include "Profile.h"

#include "game/action/Action.h"
#include "player/brain/Brain.h"

namespace player
{

Player::Player(const Profile &profile, const unsigned deck_number, const Brain &brain)
    : m_profile(profile),
      m_deck(profile.get_deck(deck_number)),
      m_brain(brain)
{
}

const std::string &Player::get_name() const
{
    return m_profile.get_name();
}

game::Action Player::next_action() const
{
    return m_brain.next_action();
}

} // namespace player
