#pragma once
#include <string>
#include <vector>
#include <list>

enum Country
{
    Lithuania,
    Estonia,
    Latvia,
    Finland,
    Norway,
    Sweden,
    Denmark,
    UnitedKingdom,
    Poland,
    Switzerland,
    Belgium,
    France,
    Germany,
    Spain,
    Portugal,
    Canada,
    UnitedStates,
    Mexico,
    Brazil,
    Peru
};

class Team;

class Player
{
private:
    // Bio and personal data
    unsigned int age_;
    // std::string fisrtName_;
    // std::string lastName_;
    std::string name_;
    Country country_;
    // std::string country_;

    //
    std::string nickname_;
    Team *team_;

    // Characteristics / Stats / Talents
    unsigned int power_;
    unsigned int kills_;
    unsigned int deaths_;

public:
    Player();
    Player(const std::string &, const Country &);
    ~Player();

    Country setCountry(const Country &);
    Country getCountry() const;

    std::string setNickname(const std::string &);
    std::string getNickname() const;

    unsigned int setAge(const unsigned int &age);
    unsigned int getAge() const;

    Team *setTeam(Team *);
    Team *getTeam() const;

    void kill(Player &);
};

Player::Player()
{
    team_ = nullptr;

    kills_ = 0;
    deaths_ = 0;
}

Player::Player(const std::string &nickname, const Country &country)
{
    country_ = country;
    nickname_ = nickname;
    kills_ = 0;
    deaths_ = 0;
}

Player::~Player() = default;

Country Player::setCountry(const Country &country)
{
    country_ = country;
    return country_;
}

Country Player::getCountry() const
{
    return country_;
}

std::string Player::setNickname(const std::string &nickname)
{
    nickname_ = nickname;
    return nickname_;
}

std::string Player::getNickname() const
{
    return nickname_;
}

unsigned int Player::setAge(const unsigned int &age)
{
    age_ = age;
    return age_;
}

unsigned int Player::getAge() const
{
    return age_;
}

Team *Player::setTeam(Team *team)
{
    team_ = team;
    return team;
}

Team *Player::getTeam() const
{
    return team_;
}

void Player::kill(Player &player)
{
    ++kills_;
    ++player.deaths_;
}
