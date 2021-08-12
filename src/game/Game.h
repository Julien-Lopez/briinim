#pragma once

#include "game/Board.h"
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

    static Status start(game::Board &board, player::Player &player_1, player::Player &player_2);
};

} // namespace game
