#include "Deck.h"

#include "DeckRecipe.h"
#include "CardsDB.h"

#include <algorithm>

namespace player
{

Deck::Deck(const std::function<size_t(void)> card_id_generator, const DeckRecipe &recipe,
    const briinim::CardsDB &cards_db)
    : m_left_commander(static_cast<card::Unit *>(cards_db.generate_card(card_id_generator(),
        recipe.get_left_commander()).release())),
      m_middle_commander(static_cast<card::Unit *>(cards_db.generate_card(card_id_generator(),
        recipe.get_middle_commander()).release())),
      m_right_commander(static_cast<card::Unit *>(cards_db.generate_card(card_id_generator(),
        recipe.get_right_commander()).release()))
{
    for (const auto &[card_key, nb] : recipe.get_cards())
    {
        for (size_t i = 0; i < nb; i++)
        {
            m_cards.push_back(cards_db.generate_card(card_id_generator(), card_key));
        }
    }
    shuffle();
}

std::unique_ptr<card::Card> Deck::pop()
{
    auto card = std::move(m_cards.back());

    m_cards.pop_back();
    return card;
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
