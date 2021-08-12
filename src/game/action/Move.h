#pragma once

#include "Action.h"

#include <array>

namespace card
{

class Card;

} // namespace card

namespace game
{

class Move final : public Action
{
public:
    explicit Move(const card::Card &target, const std::size_t new_position);

    const card::Card &get_target() const;
    std::size_t get_new_position() const;

private:
    const card::Card &m_target;
    const std::size_t m_new_position;
};

} // namespace game
