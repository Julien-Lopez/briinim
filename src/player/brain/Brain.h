#pragma once

#include "game/Reactor.h"

#include <memory>

namespace ui
{

class UserInterface;

} // namespace user_interface

namespace game
{

class Board;

} // namespace game

namespace player
{

class Brain : public game::Reactor
{
public:
    explicit Brain() = default;
    virtual ~Brain() override;
    Brain(const Brain &) = delete;
    Brain(Brain &&) = delete;
    Brain &operator=(const Brain &) = delete;
    Brain &operator=(Brain &&) = delete;

    virtual std::unique_ptr<game::Action> next_action(ui::UserInterface &ui, const game::Board &board,
        const bool player_has_the_front) const = 0;
};

} // namespace player
