#pragma once

#include "player/Deck.h"

#include <string>
#include <memory>
#include <vector>

namespace briinim
{

class CardsDB;

} // namespace briinim

namespace game
{

class Action;
class Board;

} // namespace game

namespace ui
{

class UserInterface;

} // namespace ui

namespace player
{

class Profile;
class Brain;

class Player final
{
public:
    explicit Player(const Profile &profile, const Brain &brain, Deck &deck);

    const std::string &get_name() const;

    const Deck &get_deck() const;

    std::unique_ptr<game::Action> next_action(ui::UserInterface &ui, const game::Board &board,
        const bool player_has_the_front) const;

    void add_to_hand(std::unique_ptr<card::Card> card);
    void draw(const unsigned nb);
    std::unique_ptr<card::Card> remove_from_hand(const size_t position);

    void add_to_discard_pile(std::unique_ptr<card::Card> card);

private:
    const Profile &m_profile;
    const Brain &m_brain;
    Deck &m_deck;
    std::vector<std::unique_ptr<card::Card>> m_hand;
    std::deque<std::unique_ptr<card::Card>> m_discard_pile;
};

} // namespace player
