#include "CardsDB.h"
#include "game/Game.h"
#include "player/Player.h"
#include "player/Profile.h"
#include "player/brain/Human.h"

int main(void)
{
    briinim::CardsDB cards_db;
    player::Profile profile_1("Yannick");
    player::Profile profile_2("Sébastien");

    profile_1.add_deck(1, player::Deck("Rush"));
    profile_2.add_deck(1, player::Deck("Control"));

    player::Human human_brain_1;
    player::Human human_brain_2;
    player::Player player_1(profile_1, 1, human_brain_1);
    player::Player player_2(profile_2, 1, human_brain_2);
    game::Game game(player_1, player_2);

    cards_db.load_from_file("../../data/cards.json");
    game.start();
    return 0;
}
