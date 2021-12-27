#include "CardsDB.h"
#include "game/Game.h"
#include "player/Player.h"
#include "player/Deck.h"
#include "player/Profile.h"
#include "player/brain/Human.h"
#include "user_interface/Console.h"

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
    size_t id = 0;
    const auto id_generator = [&id](void) {
        return id++;
    };
    player::Deck deck_1(id_generator, profile_1.get_deck_recipe(1), cards_db);
    player::Deck deck_2(id_generator, profile_2.get_deck_recipe(1), cards_db);
    player::Player player_1(profile_1, human_brain_1, deck_1);
    player::Player player_2(profile_2, human_brain_2, deck_2);
    ui::Console console;
    game::Game game(console, player_1, player_2);

    game.start();
    return 0;
}
