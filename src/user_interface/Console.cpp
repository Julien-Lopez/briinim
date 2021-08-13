#include "Console.h"

#include "game/action/EndTurn.h"
#include "player/Player.h"

#include <random>
#include <iostream>
#include <regex>

namespace ui
{

void Console::game_starts(const player::Player &player_1, const player::Player &player_2) const
{
    std::cout << player_1.get_name() << " VS " << player_2.get_name() << std::endl;
}

bool Console::decide_if_player_1_goes_first(const player::Player &player_1, const player::Player &player_2) const
{
    std::random_device device;
    std::default_random_engine engine(device());
    std::uniform_int_distribution<int> dist(0, 1);
    const bool player_1_goes_first = dist(engine) == 0;

    std::cout << (player_1_goes_first ? player_1 : player_2).get_name() << " goes first." << std::endl;
    return player_1_goes_first;
}

void Console::turn_starts(const player::Player &player) const
{
    std::cout << player.get_name() << " begins their turn." << std::endl;
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
