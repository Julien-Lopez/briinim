#pragma once

#include "player/Deck.h"

#include <string>
#include <memory>

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
    explicit Player(const Profile &profile, const Deck &deck, const Brain &brain);

    const std::string &get_name() const;

    const Deck &get_deck() const;

    std::unique_ptr<game::Action> next_action() const;

private:
    const Profile &m_profile;
    const Deck &m_deck;
    const Brain &m_brain;
};

} // namespace player
