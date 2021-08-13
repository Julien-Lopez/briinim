#pragma once

#include <memory>

namespace game
{

class Action;

} // namespace game

namespace ui
{

class UserInterface
{
public:
    explicit UserInterface() = default;
    virtual ~UserInterface();
    UserInterface(const UserInterface &) = delete;
    UserInterface(UserInterface &&) = delete;
    UserInterface &operator=(const UserInterface &) = delete;
    UserInterface &operator=(UserInterface &&) = delete;

    virtual std::unique_ptr<game::Action> ask_for_human_action() const = 0;
};

} // namespace ui