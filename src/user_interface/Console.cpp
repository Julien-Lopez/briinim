#include "Console.h"

#include "game/Board.h"
#include "game/action/EndTurn.h"
#include "player/Player.h"

#include <random>
#include <iostream>
#include <iomanip>
#include <regex>

namespace ui
{

static void print_hand(const std::vector<std::unique_ptr<card::Card>> &hand)
{
    if (hand.empty())
    {
        std::cout << "<empty hand>" << '\n';
        return;
    }

    std::cout << hand[0]->get_id();

    for (auto it = hand.cbegin() + 1; it != hand.cend(); it++)
    {
        std::cout << " | " << (*it)->get_id();
    }

    std::cout << '\n';
}

static void print_board(const game::Board &board)
{
    const auto print_cards = [&board](const char *prefix, const size_t begin, const size_t end) {
        for (size_t pos = begin; pos < end; pos++)
        {
            std::cout << prefix << std::setw(3) << (board[pos] == nullptr ? "" : std::to_string(board[pos]->get_id()));
        }
    };
    // Line 1
    std::cout << "     ___             ___             ___\n";
    // Line 2
    print_cards("    /", 27U, 28U);
    print_cards("\\___     ___/", 28U, 30U);
    std::cout << "\\\n";
    // Line 3
    print_cards("    \\___/", 23U, 24U);
    print_cards("\\___/", 24U, 27U);
    std::cout << "\\___/\n";
    // Line 4
    print_cards(" ___/", 18U, 19U);
    print_cards("\\___/", 19U, 23U);
    std::cout << "\\___\n";
    // Line 5
    print_cards("/", 12U, 13U);
    print_cards("\\___/", 13U, 18U);
    std::cout << "\\\n";
    // Line 6
    print_cards("\\___/", 7U, 12U);
    std::cout << "\\___/\n";
    // Line 7
    print_cards("    \\___/", 3U, 4U);
    print_cards("\\___/", 4U, 7U);
    std::cout << "\\___/\n";
    // Line 8
    print_cards("    /", 0U, 1U);
    print_cards("\\___/   \\___/", 1U, 3U);
    std::cout << "\\\n";
    // Line 9
    std::cout << "    \\___/           \\___/           \\___/\n";
}

static void print_board_and_player_hands(const game::Board &board, const player::Player &player_1,
    const player::Player &player_2)
{
    print_hand(player_2.get_hand());
    print_board(board);
    std::cout << '\n';
    print_hand(player_1.get_hand());
}

void Console::game_starts(const game::Board &board, const player::Player &player_1, const player::Player &player_2)
    const
{
    std::cout << player_1.get_name() << " VS " << player_2.get_name() << '\n';
    print_board_and_player_hands(board, player_1, player_2);
}

bool Console::decide_if_player_1_goes_first(const player::Player &player_1, const player::Player &player_2) const
{
    std::random_device device;
    std::default_random_engine engine(device());
    std::uniform_int_distribution<int> dist(0, 1);
    const bool player_1_goes_first = dist(engine) == 0;

    std::cout << (player_1_goes_first ? player_1 : player_2).get_name() << " goes first." << '\n';
    return player_1_goes_first;
}

void Console::turn_starts(const player::Player &player) const
{
    std::cout << player.get_name() << " begins their turn." << '\n';
}

std::unique_ptr<game::Action> Console::ask_for_human_action() const
{
    std::string action;

    while (true)
    {
        std::cout << "Type your action:" << '\n';
        std::getline(std::cin, action);

        const std::regex end_turn_regex("^end[\t ]*turn$", std::regex_constants::icase);

        if (std::regex_search(action, end_turn_regex))
        {
            return std::make_unique<game::EndTurn>();
        }
        std::cout << "Invalid action: " << action << '\n';
    }
}

} // namespace ui
