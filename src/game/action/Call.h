#pragma once

#include "Action.h"

#include <array>

namespace card
{

class Card;

} // namespace card

namespace game
{

class Call final : public Action
{
public:
    explicit Call(const card::Card &target, const std::size_t initial_position);

    const card::Card &get_target() const;
    std::size_t get_initial_position() const;

private:
    const card::Card &m_target;
    const std::size_t m_initial_position;
};

} // namespace game
