#include "Player.h"

#include "Profile.h"

#include "game/action/Action.h"
#include "player/brain/Brain.h"

namespace player
{

Player::Player(const Profile &profile, const Brain &brain, Deck &deck)
    : m_profile(profile),
      m_brain(brain),
      m_deck(deck)
{
}

const std::string &Player::get_name() const
{
    return m_profile.get_name();
}

const Deck &Player::get_deck() const
{
    return m_deck;
}

const std::vector<std::unique_ptr<card::Card>> &Player::get_hand() const
{
    return m_hand;
}

std::unique_ptr<game::Action> Player::next_action(ui::UserInterface &ui, const game::Board &board,
    const bool player_has_the_front) const
{
    return m_brain.next_action(ui, board, player_has_the_front);
}

void Player::add_to_hand(std::unique_ptr<card::Card> card)
{
    m_hand.push_back(std::move(card));
}

void Player::draw(const unsigned nb)
{
    for (unsigned i = 0; i < nb; i++)
    {
        add_to_hand(m_deck.pop());
    }
}

std::unique_ptr<card::Card> Player::remove_from_hand(const size_t position)
{
    auto card = std::move(m_hand[position]);

    m_hand.erase(m_hand.cbegin() + static_cast<std::vector<std::unique_ptr<card::Card>>::difference_type>(position));
    return card;
}

void Player::add_to_discard_pile(std::unique_ptr<card::Card> card)
{
    m_discard_pile.push_back(std::move(card));
}

} // namespace player
