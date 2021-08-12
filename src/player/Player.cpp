#include "Player.h"

#include "Profile.h"

#include "game/action/Action.h"
#include "player/brain/Brain.h"

namespace player
{

Player::Player(const Profile &profile, const unsigned deck_number, const briinim::CardsDB &cards_db, const Brain &brain)
    : m_profile(profile),
      m_deck(profile.get_deck_recipe(deck_number), cards_db),
      m_brain(brain)
{
}

const std::string &Player::get_name() const
{
    return m_profile.get_name();
}

const Deck &Player::get_deck() const
{
    return m_deck;
}

game::Action Player::next_action() const
{
    return m_brain.next_action();
}

} // namespace player
