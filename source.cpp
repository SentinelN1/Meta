#include <iostream>
#include "player_class.hpp"
#include "team_class.hpp"

int main()
{
    Player player_J1m("J1m", France);
    Player player_s1ndy("s1ndy", Finland);
    Player player_AliaN("AliaN", Switzerland);
    Player player_Arche("Arche", Switzerland);
    Player player_M3rCuRy("M3rCuRy", France);

    // std::cout << player_J1m.getNickname() << " " << player_J1m.getCountry() << "\n";
    std::cout << player_s1ndy.getNickname() << "\n";

    Team team_Sirius;
    team_Sirius.setName("Sirius");

    // std::cout << team_Sirius.getName() << "\n";

    team_Sirius.addPlayer(&player_s1ndy);
    std::cout << player_s1ndy.getTeam()->getName() << "\n";

    return 0;
}
