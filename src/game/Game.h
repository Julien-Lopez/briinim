#pragma once

#include "player/Player.h"

#include <vector>

namespace game
{

class Game
{
public:
    explicit Game(const player::Player &player_1, const player::Player &player_2);

    void start() const;

private:
    const player::Player &m_player_1;
    const player::Player &m_player_2;
};

} // namespace game
