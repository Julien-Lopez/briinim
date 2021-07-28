#pragma once

#include <string>

namespace card
{

enum class Species
{
    ANY,
    DWARF,
    ELF,
    HUMAN,
    ORC,
};

inline constexpr const char *s_species_any_key = "Any";
inline constexpr const char *s_species_dwarf_key = "Dwarf";
inline constexpr const char *s_species_elf_key = "Elf";
inline constexpr const char *s_species_human_key = "Human";
inline constexpr const char *s_species_orc_key = "Orc";

Species species_from_string(const std::string &s);

} // namespace card
