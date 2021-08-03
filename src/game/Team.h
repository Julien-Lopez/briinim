#pragma once

#include "player/Player.h"

namespace game
{

class Team
{
public:
    explicit Team(const std::string &name);

    /**
     * \brief Returns the next player to play.
     *
     * \return The next player to play.
     */
    const player::Player &next_player() const;

private:
    std::string m_name;
    std::vector<player::Player> m_players;
    mutable std::vector<player::Player>::const_iterator m_next_player;
};

} // namespace game
