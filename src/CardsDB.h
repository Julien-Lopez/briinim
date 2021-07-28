#pragma once

#include "card/Card.h"

#include <filesystem>
#include <unordered_map>
#include <string>

namespace briinim
{

class CardsDB
{
public:
    card::Card& operator[](const std::string &key);
    const card::Card& operator[](const std::string &key) const;
    card::Card& operator[](std::string &&key);
    const card::Card& operator[](std::string &&key) const;

    void load_from_file(const std::filesystem::path &file);

private:
    static constexpr const char *s_units_key = "units";
    static constexpr const char *s_effects_key = "effects";
    static constexpr const char *s_name_key = "name";
    static constexpr const char *s_rank_key = "rank";
    static constexpr const char *s_species_key = "species";
    static constexpr const char *s_attributes_key = "attributes";
    static constexpr const char *s_atk_key = "atk";
    static constexpr const char *s_range_key = "range";
    static constexpr const char *s_movement_key = "movement";
    static constexpr const char *s_hp_key = "hp";

    std::unordered_map<std::string, card::Card> m_db;
};

} // namespace briinim
