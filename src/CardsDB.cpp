#include "CardsDB.h"

#include "card/Unit.h"

#include <nlohmann/json.hpp>
#include <fstream>

namespace briinim
{

std::vector<card::Effect> effects_from_json(const nlohmann::json &json);
std::vector<card::Species> species_from_json(const nlohmann::json &json);
std::vector<card::Attribute> attributes_from_json(const nlohmann::json &json);

card::Card& CardsDB::operator[](const std::string &key)
{
    return m_db.at(key);
}

const card::Card& CardsDB::operator[](const std::string &key) const
{
    return m_db.at(key);
}

card::Card& CardsDB::operator[](std::string &&key)
{
    return m_db.at(key);
}

const card::Card& CardsDB::operator[](std::string &&key) const
{
    return m_db.at(key);
}

void CardsDB::load_from_file(const std::filesystem::path &file)
{
    std::ifstream stream(file);
    nlohmann::json json;

    stream >> json;

    const auto &units = json[s_units_key];

    for (const auto &unit : units)
    {
        const auto name = unit[s_name_key].get<std::string>();
        const auto rank = unit.contains(s_rank_key) ? unit[s_rank_key].get<unsigned>() : 0U;
        const auto atk = unit[s_atk_key].get<size_t>();
        const auto range = unit[s_range_key].get<size_t>();
        const auto movement = unit[s_movement_key].get<size_t>();
        const auto hp = unit[s_hp_key].get<size_t>();
        m_db.emplace(name, card::Unit(std::string(name), effects_from_json(unit[s_effects_key]), rank,
            species_from_json(unit[s_species_key]), attributes_from_json(unit[s_attributes_key]), atk, range, movement,
            hp));
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
