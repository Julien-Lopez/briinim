#pragma once

#include "Brain.h"

namespace player
{

class Human : public Brain
{
public:
    // Implements Brain //
    virtual game::Action next_action() const override;

    // Implements Reactor //
    virtual std::optional<game::Action> react_to_action(const game::Action &action) const override;
};

} // namespace player
