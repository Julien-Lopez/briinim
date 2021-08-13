#pragma once

#include "game/Board.h"
#include "player/Player.h"

#include <vector>

namespace ui
{

class UserInterface;

} // namespace ui

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

    explicit Game(ui::UserInterface &ui, player::Player &player_1, player::Player &player_2);

    Status start(void);

private:
    ui::UserInterface &m_ui;
    player::Player &m_player_1;
    player::Player &m_player_2;
    game::Board m_board;
};

} // namespace game
