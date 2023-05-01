#include <iostream>
#include "player.hpp"
#include "team.hpp"
#include "match.hpp"

using std::cout;

int main()
{
    Team Legion("Legion");
    Player Felix("Felix", Canada, &Legion);
    Player KvN("KvN", Canada, &Legion);
    Player Oliver("Oliver", Canada, &Legion);
    Player MicroN("MicroN", Canada, &Legion);
    Player R3D("R3D", Canada, &Legion);

    Team CRYSTAL("CRYSTAL");
    Player StorM("StorM", Brazil, &CRYSTAL);
    Player BlitZz("BlitZz", Brazil, &CRYSTAL);
    Player CNBL("CNBL", Brazil, &CRYSTAL);
    Player ZENN("ZENN", Brazil, &CRYSTAL);
    Player NoiSe("NoiSe", Brazil, &CRYSTAL);

    // Team Sirius("Sirius");
    // Player J1m("J1m", France, &Sirius);
    // Player s1ndy("s1ndy", Finland, &Sirius);
    // Player AliaN("AliaN", Switzerland, &Sirius);
    // Player Arche("Arche", Switzerland, &Sirius);
    // Player M3rCuRy("M3rCuRy", France, &Sirius);
    // Player FrOzeN("FrOzeN", Switzerland, &Sirius);

    cout << BlitZz.getTeam()->getName() << "\t" << BlitZz.getNickname() << "\n";

    return 0;
}
