#include "Human.h"

#include "user_interface/UserInterface.h"
#include "game/action/Action.h"

namespace player
{

std::unique_ptr<game::Action> Human::next_action(ui::UserInterface &ui, const game::Board &, const bool) const
{
    return ui.ask_for_human_action();
}

std::unique_ptr<game::Action> Human::react_to_action(const game::Action &) const
{
    return nullptr;
}

} // namespace player
