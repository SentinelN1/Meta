#pragma once
#include <algorithm>
#include <map>
#include <unordered_set>
#include "player.hpp"

using std::string;
using std::vector;
using std::list;
using std::map;
using std::unordered_set;
using std::find;

#define TEAM_SIZE 5

class Team
{
private:
    int id_;
    string name_;
    map<int, Player *> activePlayers_;
    unordered_set<Player *> inactivePlayers_;
    Player *coach_;

public:
    Team(const string &);
    ~Team();

    void setName(const string &);
    string getName() const;

    void addPlayerToActive(Player *, const int &);
    void addPlayerToInactive(Player *);
    map<int, Player *> getActivePlayers() const;
    unordered_set<Player *> getInactivePlayers() const;
    void removePlayer(Player *);

    void addCoach(Player *coach);
    void removeCoach();
    Player *getCoach() const;
};

// Constructor
Team::Team(const string &name)
{
    name_ = name;
}

// Destructor
Team::~Team()
{
    for (auto player : activePlayers_)
    {
        if (player.second)
        {
            removePlayer(player.second);
        }
    }

    for (auto player : inactivePlayers_)
    {
        if (player)
        {
            removePlayer(player);
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

void Team::removePlayer(Player *player)
{
    if (player->getTeam() == this)
    {
        if (player == coach_)
        {
            coach_ = nullptr;
            player->isCoach_ = false;
        }
        else if (activePlayers_[player->getPosition()] == player)
        {
            activePlayers_[player->getPosition()] = nullptr;
        }
        else
        {
            inactivePlayers_.erase(player);
        }

        player->setTeam(nullptr);
        player->setInactive();
        player->isCaptain_ = false;
        player->isCoach_ = false;
        player->setPosition(0);
    }
}

void Team::addPlayerToInactive(Player *player)
{
    if (player)
    {
        if (player->getTeam())
        {
            player->getTeam()->removePlayer(player);
        }
        inactivePlayers_.insert(player);
        player->setTeam(this);
        player->setInactive();
        player->setPosition(0);
    }
}

unordered_set<Player *> Team::getInactivePlayers() const
{
    return inactivePlayers_;
}

void Team::addPlayerToActive(Player *player, const int &position)
{
    if (player)
    {
        if (position < 1 || position > 5)
        {
            addPlayerToInactive(player);
            return;
        }

        if (activePlayers_[position])
        {
            addPlayerToInactive(activePlayers_[position]);
        }

        if (player->getTeam())
        {
            player->getTeam()->removePlayer(player);
        }

        activePlayers_[position] = player;
        player->setTeam(this);
        player->setActive();
        player->setPosition(position);
    }
}

map<int, Player *> Team::getActivePlayers() const
{
    return activePlayers_;
}

void Team::addCoach(Player *coach)
{
    if (coach)
    {
        if (coach->getTeam())
        {
            coach->getTeam()->removePlayer(coach);
        }
        coach_ = coach;
        coach->setTeam(this);
        coach->isCoach_ = true;
    }
}

void Team::removeCoach()
{
    if (coach_)
    {
        if (coach_->getTeam() == this)
        {
            coach_->getTeam()->removePlayer(coach_);
        }
    }
}

Player *Team::getCoach() const
{
    return coach_;
}