#include "Team.h"

namespace game
{

Team::Team(const std::string &name)
    : m_name(name),
      m_next_player(m_players.cbegin())
{
}

const player::Player &Team::next_player() const
{
    const auto it = m_next_player;

    m_next_player = m_next_player++;
    if (m_next_player == m_players.cend())
    {
        m_next_player = m_players.cbegin();
    }
    return *it;
}

} // namespace game
