#pragma once

#include "UserInterface.h"

namespace ui
{

class Console final : public UserInterface
{
public:
    // Implements UserInterface //
    virtual bool decide_if_player_1_goes_first() const override;
    virtual std::unique_ptr<game::Action> ask_for_human_action() const override;
};

} // namespace ui
