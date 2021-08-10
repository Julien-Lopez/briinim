#pragma once

#include <string>

namespace game
{

class Action;

} // namespace game

namespace player
{

class Profile;
class Deck;
class Brain;

class Player
{
public:
    explicit Player(const Profile &profile, const unsigned deck_number, const Brain &brain);

    const std::string &get_name() const;

    game::Action next_action() const;

private:
    const Profile &m_profile;
    const Deck &m_deck;
    const Brain &m_brain;
};

} // namespace player
