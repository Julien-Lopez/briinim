#pragma once

#include "card/Card.h"

#include <filesystem>
#include <unordered_map>
#include <string>
#include <functional>
#include <memory>

namespace briinim
{

class CardsDB final
{
public:
    std::unique_ptr<card::Card> generate_card(const size_t id, const card::Card::key_t &key) const;
    std::unique_ptr<card::Card> generate_card(const size_t id, card::Card::key_t &&key) const;

    void load_from_file(const std::filesystem::path &file);

private:
    static constexpr const char *s_units_key = "units";
    static constexpr const char *s_spells_key = "spells";

    static constexpr const char *s_effects_key = "effects";
    static constexpr const char *s_name_key = "name";
    static constexpr const char *s_rank_key = "rank";
    static constexpr const char *s_species_key = "species";
    static constexpr const char *s_attributes_key = "attributes";
    static constexpr const char *s_atk_key = "atk";
    static constexpr const char *s_range_key = "range";
    static constexpr const char *s_movement_key = "movement";
    static constexpr const char *s_max_hp_key = "max_hp";

    std::unordered_map<card::Card::key_t, std::function<std::unique_ptr<card::Card>(const size_t id)>> m_db;
};

} // namespace briinim
