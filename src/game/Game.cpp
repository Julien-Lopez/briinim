#include "Game.h"

#include "globals.h"
#include "utils/logs/ScopeLogger.h"

#include "player/brain/Brain.h"
#include "player/Deck.h"
#include "game/action/Action.h"

namespace game
{

Game::Status Game::start(const player::Player &player_1, const player::Player &player_2)
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

    while (game_is_on())
    {
        // TODO
        return Game::Status::Cancelled;
    }

    return player_1_lost ? (player_2_lost ? Game::Status::Draw : Game::Status::Player2Won) : Game::Status::Player1Won;
}

} // namespace game
