#include "CardsDB.h"

#include "card/Unit.h"
#include "card/Spell.h"
#include "utils/logs/ScopeLogger.h"
#include "globals.h"

#include <nlohmann/json.hpp>
#include <fstream>

namespace briinim
{

std::vector<card::Effect> effects_from_json(const nlohmann::json &json);
std::vector<card::Species> species_from_json(const nlohmann::json &json);
std::vector<card::Attribute> attributes_from_json(const nlohmann::json &json);

std::unique_ptr<card::Card> CardsDB::generate_card(const size_t id, const card::Card::key_t &key) const
{
    return m_db.at(key)(id);
}

std::unique_ptr<card::Card> CardsDB::generate_card(const size_t id, card::Card::key_t &&key) const
{
    return m_db.at(key)(id);
}

void CardsDB::load_from_file(const std::filesystem::path &file)
{
    const utils::ScopeLogger scope_logger(briinim::g_logger, utils::Logger::Module::Main, "CardsDB::load_from_file("
        + file.string() + ")");
    std::ifstream stream(file);
    nlohmann::json json;

    stream >> json;

    const auto &units = json[s_units_key];

    for (const auto &unit : units)
    {
        const auto name = unit[s_name_key].get<std::string>();
        const auto rank = unit.contains(s_rank_key) ? unit[s_rank_key].get<unsigned>() : 0U;
        const auto atk = unit[s_atk_key].get<unsigned>();
        const auto range = unit[s_range_key].get<unsigned>();
        const auto movement = unit[s_movement_key].get<unsigned>();
        const auto max_hp = unit[s_max_hp_key].get<unsigned>();
        m_db.emplace(name, [=](const size_t id) {
            return std::make_unique<card::Unit>(id, name, effects_from_json(unit[s_effects_key]), rank,
                species_from_json(unit[s_species_key]), attributes_from_json(unit[s_attributes_key]), atk, range,
                movement, max_hp);
        });
    }

    const auto &spells = json[s_spells_key];

    for (const auto &spell : spells)
    {
        const auto name = spell[s_name_key].get<std::string>();
        m_db.emplace(name, [=](const size_t id) {
            return std::make_unique<card::Spell>(id, name, effects_from_json(spell[s_effects_key]));
        });
    }
}

std::vector<card::Effect> effects_from_json(const nlohmann::json &)
{
    std::vector<card::Effect> effects;

    // TODO: Effects
    return effects;
}

std::vector<card::Species> species_from_json(const nlohmann::json &json)
{
    std::vector<card::Species> species;

    for (const auto &x : json)
    {
        species.push_back(card::species_from_string(x.get<std::string>()));
    }
    return species;
}

std::vector<card::Attribute> attributes_from_json(const nlohmann::json &json)
{
    std::vector<card::Attribute> attributes;

    for (const auto &x : json)
    {
        attributes.push_back(card::attribute_from_string(x.get<std::string>()));
    }
    return attributes;
}

} // namespace briinim
