#include "Game.h"

#include "globals.h"
#include "utils/logs/ScopeLogger.h"

namespace game
{

Game::Game(const std::vector<Team> &teams)
    : m_teams(teams)
{
}

void Game::start() const
{
    const utils::ScopeLogger scope_logger(briinim::g_logger, utils::Logger::Module::Game, "Game::start()");
}

} // namespace game
