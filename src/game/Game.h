#pragma once

#include "player/Player.h"

#include <vector>

namespace game
{

class Game
{
public:
    enum class Status
    {
        Player1Won,
        Player2Won,
        Draw,
        Cancelled,
    };

    static Status start(const player::Player &player_1, const player::Player &player_2);
};

} // namespace game
