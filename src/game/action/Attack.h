#pragma once

#include "Action.h"

namespace card
{

class Card;

} // namespace card

namespace game
{

class Attack final : public Action
{
public:
    explicit Attack(const card::Card &source, const card::Card &target);

    const card::Card &get_source() const;
    const card::Card &get_target() const;

private:
    const card::Card &m_source;
    const card::Card &m_target;
};

} // namespace game
