#include "Game.h"

#include "globals.h"
#include "utils/logs/ScopeLogger.h"

#include "player/brain/Brain.h"
#include "game/action/Action.h"

namespace game
{

Game::Game(const player::Player &player_1, const player::Player &player_2)
    : m_player_1(player_1),
      m_player_2(player_2)
{
}

void Game::start() const
{
    const utils::ScopeLogger scope_logger(briinim::g_logger, utils::Logger::Module::Game, "Game::start()");

    briinim::g_logger(utils::Logger::Module::Game, utils::Logger::Type::Info, m_player_1.get_name() + " vs "
        + m_player_2.get_name());
}

} // namespace game
