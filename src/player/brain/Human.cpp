#include "Human.h"

#include "game/action/EndTurn.h"

namespace player
{

game::Action Human::next_action() const
{
    return game::EndTurn();
}

std::optional<game::Action> Human::react_to_action(const game::Action &) const
{
    return std::nullopt;
}

} // namespace player
