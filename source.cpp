#include <iostream>
#include "player.h"
#include "team.h"
#include "script.h"

int main()
{
    // CRYSTAL.addPlayerToActive(&StorM, 1);
    // CRYSTAL.addPlayerToActive(&BlitZz, 2);
    // CRYSTAL.addPlayerToActive(&CNBL, 3);
    // CRYSTAL.addPlayerToActive(&ZENN, 4);
    // CRYSTAL.addPlayerToActive(&NoiSe, 5);
    // CRYSTAL.setCoach(&TOX1C);

    CRYSTAL.setActivePlayers({&StorM, &BlitZz, &CNBL, &ZENN, &NoiSe});
    CRYSTAL.setCoach(&TOX1C);

    std::cout << CRYSTAL.getActivePlayers().at(1)->getNickname() << "\n";
    std::cout << CRYSTAL.getActivePlayers().at(2)->getNickname() << "\n";
    std::cout << CRYSTAL.getActivePlayers().at(3)->getNickname() << "\n";
    std::cout << CRYSTAL.getActivePlayers().at(4)->getNickname() << "\n";
    std::cout << CRYSTAL.getActivePlayers().at(5)->getNickname() << "\n";
    std::cout << CRYSTAL.getCoach()->getNickname() << "\n";

    return 0;
}
