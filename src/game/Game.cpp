#include "Game.h"

#include "globals.h"
#include "utils/logs/ScopeLogger.h"

#include "player/brain/Brain.h"
#include "player/Deck.h"
#include "game/action/Action.h"
#include "user_interface/UserInterface.h"
#include "card/Unit.h"

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

Game::Status Game::start()
{
    const utils::ScopeLogger scope_logger(briinim::g_logger, utils::Logger::Module::Game, "Game::start("
        + m_player_1.get_name() + " vs " + m_player_2.get_name() + ")");

    m_board[0U] = &m_player_1.get_deck().get_left_commander();
    m_board[1U] = &m_player_1.get_deck().get_middle_commander();
    m_board[2U] = &m_player_1.get_deck().get_right_commander();
    m_board[27U] = &m_player_2.get_deck().get_right_commander();
    m_board[28U] = &m_player_2.get_deck().get_middle_commander();
    m_board[29U] = &m_player_2.get_deck().get_left_commander();

    m_ui.game_starts(m_board, m_player_1, m_player_2);
    return game_loop();
}

Game::Status Game::game_loop()
{
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
    auto turn = 1U;
    auto current_player_is_player_1 = m_ui.decide_if_player_1_goes_first(m_player_1, m_player_2);

    while (game_is_on())
    {
        auto &current_player = current_player_is_player_1 ? m_player_1 : m_player_2;
        auto &opponent = current_player_is_player_1 ? m_player_2 : m_player_1;

        m_ui.turn_starts(current_player);

        std::unique_ptr<game::Action> action = nullptr;

        do
        {
            action = current_player.next_action(m_ui, m_board, current_player_is_player_1);
            // TODO
        } while (execute_action(m_board, current_player, opponent, *action));

        turn++;
        current_player_is_player_1 = not current_player_is_player_1;
    }

    return player_1_lost ? (player_2_lost ? Game::Status::Draw : Game::Status::Player2Won) : Game::Status::Player1Won;
}

} // namespace game
