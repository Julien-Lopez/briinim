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
    player::DeckRecipe rush_recipe("Rush");
    player::DeckRecipe control_recipe("Control");

    cards_db.load_from_file("../../data/cards.json");
    rush_recipe.set_left_commander("Shaaron, the Resourceful");
    rush_recipe.set_middle_commander("Lokar, the Brute");
    rush_recipe.set_right_commander("Banh, the Godly");
    control_recipe.set_left_commander("Shaaron, the Resourceful");
    control_recipe.set_middle_commander("Lokar, the Brute");
    control_recipe.set_right_commander("Banh, the Godly");
    profile_1.add_deck_recipe(1, rush_recipe);
    profile_2.add_deck_recipe(1, control_recipe);

    player::Human human_brain_1;
    player::Human human_brain_2;
    player::Player player_1(profile_1, 1, cards_db, human_brain_1);
    player::Player player_2(profile_2, 1, cards_db, human_brain_2);

    game::Game::start(player_1, player_2);
    return 0;
}
