#pragma once

#include "game/Team.h"

#include <vector>

namespace game
{

class Game
{
public:
    explicit Game(const std::vector<Team> &teams);

    void start() const;

private:
    const std::vector<Team> m_teams;
};

} // namespace game
