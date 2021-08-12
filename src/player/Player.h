#pragma once

#include "player/Deck.h"

#include <string>

namespace briinim
{

class CardsDB;

} // namespace briinim

namespace game
{

class Action;

} // namespace game

namespace player
{

class Profile;
class Brain;

class Player final
{
public:
    explicit Player(const Profile &profile, const unsigned deck_number, const briinim::CardsDB &cards_db, const Brain &brain);

    const std::string &get_name() const;

    const Deck &get_deck() const;

    game::Action next_action() const;

private:
    const Profile &m_profile;
    const Deck m_deck;
    const Brain &m_brain;
};

} // namespace player
