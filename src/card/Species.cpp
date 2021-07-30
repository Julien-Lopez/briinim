#include "Species.h"

namespace card
{

Species species_from_string(const std::string &s)
{
    return s == s_species_dwarf_key ? Species::DWARF
        : s == s_species_elf_key ? Species::ELF
        : s == s_species_human_key ? Species::HUMAN
        : s == s_species_orc_key ? Species::ORC
        : Species::ANY;
}

} // namespace card
