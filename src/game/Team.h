#pragma once

#include "player/Player.h"

namespace game
{

class Team
{
public:
    explicit Team(const std::string &name);

private:
    std::string m_name;
    std::vector<player::Player> m_players;
};

} // namespace game
