#pragma once
#include <random>
#include "player.hpp"
#include "team.hpp"

using std::time;
using std::srand;
using std::rand;

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
