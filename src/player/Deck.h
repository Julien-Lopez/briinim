#pragma once

#include "card/Card.h"

#include <unordered_map>
#include <string>

namespace player
{

class Deck
{
public:
    explicit Deck(const std::string &name);

    void rename(const std::string &name);
    void add_card(const card::Card::key_t &name);
    void remove_card(const card::Card::key_t &name);

private:
    std::string m_name;
    std::unordered_map<card::Card::key_t, unsigned> m_cards;
};

} // namespace player
