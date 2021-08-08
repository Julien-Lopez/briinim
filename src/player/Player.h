#pragma once

#include <string>

namespace player
{

class Profile;
class Deck;

class Player
{
public:
    explicit Player(const Profile &profile, const unsigned deck_number);

    const std::string &get_name() const;

private:
    const Profile &m_profile;
    const Deck &m_deck;
};

} // namespace player
