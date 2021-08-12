#include "Game.h"

#include "globals.h"
#include "utils/logs/ScopeLogger.h"

#include "player/brain/Brain.h"
#include "player/Deck.h"
#include "game/action/Action.h"

namespace game
{

static void execute_action(game::Board &, player::Player &, player::Player &, const Action &)
{
}

Game::Status Game::start(game::Board &board, player::Player &player_1, player::Player &player_2)
{
    const utils::ScopeLogger scope_logger(briinim::g_logger, utils::Logger::Module::Game, "Game::start("
        + player_1.get_name() + " vs " + player_2.get_name() + ")");
    bool player_1_lost;
    bool player_2_lost;
    const auto game_is_on = [&player_1, &player_1_lost, &player_2, &player_2_lost]() {
        player_1_lost = player_1.get_deck().get_left_commander().is_dead()
            and player_1.get_deck().get_middle_commander().is_dead()
            and player_1.get_deck().get_right_commander().is_dead();
        player_2_lost = player_2.get_deck().get_left_commander().is_dead()
            and player_2.get_deck().get_middle_commander().is_dead()
            and player_2.get_deck().get_right_commander().is_dead();
        return not player_1_lost and not player_2_lost;
    };
    // TODO: First player to play should be random
    bool current_player_is_player_1 = true;

    while (game_is_on())
    {
        auto &current_player = current_player_is_player_1 ? player_1 : player_2;
        auto &opponent = current_player_is_player_1 ? player_2 : player_1;
        const auto action = current_player.next_action();

        execute_action(board, current_player, opponent, *action);

        current_player_is_player_1 = not current_player_is_player_1;
    }

    return player_1_lost ? (player_2_lost ? Game::Status::Draw : Game::Status::Player2Won) : Game::Status::Player1Won;
}

} // namespace game
