#include "Deck.h"

#include "DeckRecipe.h"
#include "CardsDB.h"

#include <algorithm>

namespace player
{

Deck::Deck(const DeckRecipe &recipe, const briinim::CardsDB &cards_db)
    : m_left_commander(static_cast<card::Unit *>(cards_db[recipe.get_left_commander()].release())),
      m_middle_commander(static_cast<card::Unit *>(cards_db[recipe.get_middle_commander()].release())),
      m_right_commander(static_cast<card::Unit *>(cards_db[recipe.get_right_commander()].release()))
{
    for (const auto &[card_key, nb] : recipe.get_cards())
    {
        for (size_t i = 0; i < nb; i++)
        {
            m_cards.push_back(cards_db[card_key]);
        }
    }
    shuffle();
}

const card::Unit &Deck::get_left_commander() const
{
    return *m_left_commander;
}

const card::Unit &Deck::get_middle_commander() const
{
    return *m_middle_commander;
}

const card::Unit &Deck::get_right_commander() const
{
    return *m_right_commander;
}

void Deck::shuffle()
{
    std::random_shuffle(m_cards.begin(), m_cards.end());
}

} // namespace player
