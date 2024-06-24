#pragma once

#include "player.h"

#include <map>
#include <unordered_set>

#define TEAM_SIZE 5;

class Team
{
private:
    // int id_;
    std::string name_;

    // std::vector<Player *> activePlayers_;
    std::map<int, Player *> activePlayers_;

    Player *player1_;
    Player *player2_;
    Player *player3_;
    Player *player4_;
    Player *player5_;

    // std::list<Player *> inactivePlayers_;
    std::unordered_set<Player *> inactivePlayers_;

    Player *coach_;

public:
    Team();
    Team(const std::string &);
    ~Team();

    void setName(const std::string &);
    std::string getName() const;

    void addPlayerToActive(Player *, const int &);
    void addPlayerToInactive(Player *);

    void setActivePlayers(std::initializer_list<Player *>);
    std::map<int, Player *> getActivePlayers() const;
    std::unordered_set<Player *> getInactivePlayers() const;
    void removePlayer(Player *);

    void setCoach(Player *coach);
    void removeCoach();
    Player *getCoach() const;
};

// Constructor
Team::Team(const std::string &name)
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

void Team::setName(const std::string &name)
{
    name_ = name;
}

std::string Team::getName() const
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

std::unordered_set<Player *> Team::getInactivePlayers() const
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

void Team::setActivePlayers(std::initializer_list<Player *> players)
{
    size_t position = 1;
    for (auto player : players)
    {
        addPlayerToActive(player, position);
        position++;
    }
}

std::map<int, Player *> Team::getActivePlayers() const
{
    return activePlayers_;
}

void Team::setCoach(Player *coach)
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
