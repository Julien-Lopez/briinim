#pragma once

#include "UserInterface.h"

namespace ui
{

class Console final : public UserInterface
{
public:
    // Implements UserInterface //
    virtual void game_starts(const player::Player &player_1, const player::Player &player_2) const override;
    virtual bool decide_if_player_1_goes_first(const player::Player &player_1, const player::Player &player_2) const
        override;
    virtual void turn_starts(const player::Player &player) const override;
    virtual std::unique_ptr<game::Action> ask_for_human_action() const override;
};

} // namespace ui
