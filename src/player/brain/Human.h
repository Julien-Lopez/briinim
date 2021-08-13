#pragma once

#include "Brain.h"

namespace player
{

class Human final : public Brain
{
public:
    // Implements Brain //
    virtual std::unique_ptr<game::Action> next_action(ui::UserInterface &ui, const game::Board &board,
        const bool player_has_the_front) const override;

    // Implements Reactor //
    virtual std::unique_ptr<game::Action> react_to_action(const game::Action &action) const override;
};

} // namespace player
