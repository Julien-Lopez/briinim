#pragma once

#include "game/Reactor.h"

#include <memory>

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

    virtual std::unique_ptr<game::Action> next_action() const = 0;
};

} // namespace player
