#include "Console.h"

#include "game/action/EndTurn.h"

#include <random>
#include <iostream>
#include <regex>

namespace ui
{

bool Console::decide_if_player_1_goes_first() const
{
    std::random_device device;

    // Choose a random mean between 1 and 6
    std::default_random_engine engine(device());
    std::uniform_int_distribution<int> dist(0, 1);
    return dist(engine) == 0;
}

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
