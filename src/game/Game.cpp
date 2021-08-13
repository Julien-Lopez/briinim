#include "Game.h"

#include "globals.h"
#include "utils/logs/ScopeLogger.h"

#include "player/brain/Brain.h"
#include "player/Deck.h"
#include "game/action/Action.h"

namespace game
{

Game::Game(ui::UserInterface &ui, player::Player &player_1, player::Player &player_2)
    : m_ui(ui),
      m_player_1(player_1),
      m_player_2(player_2)
{
}

static bool execute_action(game::Board &, player::Player &, player::Player &, const Action &)
{
    return false;
}

Game::Status Game::start(void)
{
    const utils::ScopeLogger scope_logger(briinim::g_logger, utils::Logger::Module::Game, "Game::start("
        + m_player_1.get_name() + " vs " + m_player_2.get_name() + ")");
    bool player_1_lost;
    bool player_2_lost;
    const auto game_is_on = [this, &player_1_lost, &player_2_lost]() {
        player_1_lost = m_player_1.get_deck().get_left_commander().is_dead()
            and m_player_1.get_deck().get_middle_commander().is_dead()
            and m_player_1.get_deck().get_right_commander().is_dead();
        player_2_lost = m_player_2.get_deck().get_left_commander().is_dead()
            and m_player_2.get_deck().get_middle_commander().is_dead()
            and m_player_2.get_deck().get_right_commander().is_dead();
        return not player_1_lost and not player_2_lost;
    };
    unsigned turn = 1U;
    // TODO: First player to play should be random
    bool current_player_is_player_1 = true;

    while (game_is_on())
    {
        auto &current_player = current_player_is_player_1 ? m_player_1 : m_player_2;
        auto &opponent = current_player_is_player_1 ? m_player_2 : m_player_1;
        const auto action = current_player.next_action(m_ui, m_board, current_player_is_player_1);

        while (execute_action(m_board, current_player, opponent, *action))
        {
            // TODO
        }

        turn++;
        current_player_is_player_1 = not current_player_is_player_1;
    }

    return player_1_lost ? (player_2_lost ? Game::Status::Draw : Game::Status::Player2Won) : Game::Status::Player1Won;
}

} // namespace game
