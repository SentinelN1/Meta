#pragma once
#include <algorithm>
#include "player.hpp"

#define TEAM_SIZE 5

using std::string, std::vector, std::list;

class Team
{
private:
    unsigned long long int id_;
    string name_;
    string tag_;
    Player *coach_;
    vector<Player *> activePlayers_;
    list<Player *> inactivePlayers_;

public:
    Team(/*const unsigned int &, */ const string &);
    ~Team();

    void setName(const string &);
    void addInactivePlayer(Player *);
    void addActivePlayer(Player *, const int &);
    void *setCoach(Player *coach);

    string getName() const;
    list<Player *> getInactivePlayers() const;
    vector<Player *> getActivePlayers() const;
    Player *getCoach() const;
};

// Constructor
Team::Team(/*const unsigned int &id, */ const string &name)
{
    // id_ = id;
    name_ = name;
    activePlayers_ = vector<Player *>(TEAM_SIZE);
}

// Destructor
Team::~Team() // = default;
{
    for (auto player : activePlayers_)
    {
        if (player)
        {
            player->setTeam(nullptr);
            player->setPosition(-1);
        }
    }

    for (auto player : inactivePlayers_)
    {
        if (player)
        {
            player->setTeam(nullptr);
        }
    }
}

void Team::setName(const string &name)
{
    name_ = name;
}

string Team::getName() const
{
    return name_;
}

void Team::addInactivePlayer(Player *player)
{
    if (player)
    {
        inactivePlayers_.push_back(player);
        player->setTeam(this);
        player->setPosition(-1);
    }
}

list<Player *> Team::getInactivePlayers() const
{
    return inactivePlayers_;
}

void Team::addActivePlayer(Player *player, const int &position)
{
    if (player)
    {
        if (position < 0 || position >= 5)
        {
            addInactivePlayer(player);
            return;
        }

        if (activePlayers_[position])
        {
            addInactivePlayer(activePlayers_[position]);
        }

        activePlayers_[position] = player;
        player->setPosition(position);
        
        // TO DO : Remove player from previous team
        Team *pTeam = player->getTeam();
        if (pTeam)
        {
            // pTeam->inactivePlayers_.erase()
        }

        player->setTeam(this);
        player->setActive();
    }
}

vector<Player *> Team::getActivePlayers() const
{
    return activePlayers_;
}
