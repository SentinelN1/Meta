#include <iostream>
#include "player.hpp"
#include "team.hpp"
#include "match.hpp"

using std::cout;

int main()
{
    Team Legion("Legion");
    Player Felix("Felix", Canada);
    Player KvN("KvN", Canada);
    Player Oliver("Oliver", Canada);
    Player MicroN("MicroN", Canada);
    Player R3D("R3D", Canada);
    Player SpaceLocker("SpaceLocker", Canada);
    // Player F1T("F1T", Canada);
    Player ConCorSe("ConCorSe", Canada);

    Legion.addPlayerToActive(&Felix, 1);
    Legion.addPlayerToActive(&KvN, 2);
    Legion.addPlayerToActive(&Oliver, 3);
    Legion.addPlayerToActive(&MicroN, 4);
    Legion.addPlayerToActive(&R3D, 5);
    Legion.addPlayerToInactive(&SpaceLocker);
    Legion.addCoach(&ConCorSe);

    Team CRYSTAL("CRYSTAL");
    Player StorM("StorM", Brazil);
    Player BlitZz("BlitZz", Brazil);
    Player CNBL("CNBL", Brazil);
    Player ZENN("ZENN", Brazil);
    Player NoiSe("NoiSe", Brazil);
    Player TOX1C("TOX1C", Brazil);

    CRYSTAL.addPlayerToActive(&StorM, 1);
    CRYSTAL.addPlayerToActive(&BlitZz, 2);
    CRYSTAL.addPlayerToActive(&CNBL, 3);
    CRYSTAL.addPlayerToActive(&ZENN, 4);
    CRYSTAL.addPlayerToActive(&NoiSe, 5);
    CRYSTAL.addCoach(&TOX1C);

    // Team Sirius("Sirius");
    // Player J1m("J1m", France);
    // Player s1ndy("s1ndy", Finland);
    // Player AliaN("AliaN", Switzerland);
    // Player Arche("Arche", Switzerland);
    // Player M3rCuRy("M3rCuRy", France);
    // Player FrOzeN("FrOzeN", Switzerland);

    cout << BlitZz.getTeam()->getName() << " " << BlitZz.getNickname() << "\n";
    cout << CRYSTAL.getCoach()->getNickname() << "\n";
    
    return 0;
}
