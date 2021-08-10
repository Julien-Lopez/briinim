#pragma once

#include <optional>

namespace game
{

class Action;

class Reactor
{
public:
    explicit Reactor() = default;
    virtual ~Reactor();
    Reactor(const Reactor &) = delete;
    Reactor(Reactor &&) = delete;
    Reactor &operator=(const Reactor &) = delete;
    Reactor &operator=(Reactor &&) = delete;

    virtual std::optional<game::Action> react_to_action(const game::Action &action) const = 0;
};

} // namespace game
