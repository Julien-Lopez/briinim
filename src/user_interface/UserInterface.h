#pragma once

#include <memory>

namespace player
{

class Player;

} // namespace player

namespace game
{

class Action;

} // namespace game

namespace ui
{

class UserInterface
{
public:
    explicit UserInterface() = default;
    virtual ~UserInterface();
    UserInterface(const UserInterface &) = delete;
    UserInterface(UserInterface &&) = delete;
    UserInterface &operator=(const UserInterface &) = delete;
    UserInterface &operator=(UserInterface &&) = delete;

    virtual void game_starts(const player::Player &player_1, const player::Player &player_2) const = 0;
    virtual bool decide_if_player_1_goes_first(const player::Player &player_1, const player::Player &player_2) const
        = 0;
    virtual void turn_starts(const player::Player &player) const = 0;
    virtual std::unique_ptr<game::Action> ask_for_human_action() const = 0;
};

} // namespace ui
