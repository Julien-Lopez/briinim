#include "Console.h"

#include "game/action/EndTurn.h"

#include <iostream>
#include <regex>

namespace ui
{

std::unique_ptr<game::Action> Console::ask_for_human_action() const
{
    std::string action;

    while (true)
    {
        std::cout << "Type your action:" << std::endl;
        std::getline(std::cin, action);

        const std::regex end_turn_regex("^end[\t ]*turn$", std::regex_constants::icase);

        if (std::regex_search(action, end_turn_regex))
        {
            return std::make_unique<game::EndTurn>();
        }
        std::cout << "Invalid action: " << action << std::endl;
    }
}

} // namespace ui
