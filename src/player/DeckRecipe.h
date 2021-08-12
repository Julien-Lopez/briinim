#pragma once

#include "card/Card.h"

#include <unordered_map>
#include <string>

namespace player
{

class DeckRecipe final
{
public:
    explicit DeckRecipe(const std::string &name);

    void rename(const std::string &name);
    std::unordered_map<card::Card::key_t, unsigned> get_cards() const;
    void add_card(const card::Card::key_t &key);
    void remove_card(const card::Card::key_t &key);
    const card::Card::key_t &get_left_commander() const;
    void set_left_commander(const card::Card::key_t &key);
    const card::Card::key_t &get_middle_commander() const;
    void set_middle_commander(const card::Card::key_t &key);
    const card::Card::key_t &get_right_commander() const;
    void set_right_commander(const card::Card::key_t &key);

private:
    std::string m_name;
    std::unordered_map<card::Card::key_t, unsigned> m_cards;
    card::Card::key_t m_left_commander;
    card::Card::key_t m_middle_commander;
    card::Card::key_t m_right_commander;
};

} // namespace player
