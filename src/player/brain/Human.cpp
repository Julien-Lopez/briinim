#include "Human.h"

#include "game/action/EndTurn.h"

namespace player
{

std::unique_ptr<game::Action> Human::next_action() const
{
    return std::make_unique<game::EndTurn>();
}

std::unique_ptr<game::Action> Human::react_to_action(const game::Action &) const
{
    return nullptr;
}

} // namespace player
