#pragma once
#include <random>
#include "player.hpp"
#include "team.hpp"

using std::srand, std::rand, std::time;

class Match
{
private:
public:
    Match(Team *teamA, Team *teamB)
    {
        // srand(time(0));
        // int pow = rand() % 6;
    }

    ~Match() = default;
};
