#pragma once
#include "player_class.hpp"

#define TEAM_SIZE 5

class Team
{
private:
    std::string name_;
    std::vector<Player *> activePlayers_;
    std::list<Player *> inactivePlayers_;

public:
    Team();
    Team(const std::string &);
    ~Team();
    void addPlayer(Player *);
    void addPlayer(Player *, const int &);
    std::string setName(const std::string &);
    std::string getName() const;
};

Team::Team()
{
    activePlayers_ = std::vector<Player *>(TEAM_SIZE);
}

Team::Team(const std::string &name)
{
    name_ = name;
    activePlayers_ = std::vector<Player *>(TEAM_SIZE);
}

Team::~Team() = default;

void Team::addPlayer(Player *player)
{
    if (player)
    {
        inactivePlayers_.push_back(player);
        player->setTeam(this);
    }
}

void Team::addPlayer(Player *player, const int &position)
{
    if (player)
    {
        if (activePlayers_[position])
        {
            addPlayer(activePlayers_[position]);
        }
        activePlayers_[position] = player;
    }
}

std::string Team::setName(const std::string &name)
{
    name_ = name;
    return name_;
}

std::string Team::getName() const
{
    return name_;
}
