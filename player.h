#pragma once

#include <string>

enum Country
{
    Australia,
    India,
    Vietnam,
    New_Zealand,
    Japan,
    Pakistan,
    South_Korea,
    China,
    Hong_Kong,
    Malaysia,
    Philippines,
    Indonesia,
    Mongolia,
    Uzbekistan,
    Kazakhstan,
    Russia,
    Ukraine,
    Belarus,
    Lithuania,
    Estonia,
    Latvia,
    Slovakia,
    Serbia,
    Chezh_Republic,
    Bosina_and_Herzegovina,
    Montenegro,
    Kosovo,
    Greece,
    North_Macedonia,
    Turkey,
    Israel,
    Jordan,
    Syria,
    Lebanon,
    Romania,
    Bulgaria,
    Finland,
    Norway,
    Sweden,
    Denmark,
    United_Kingdom,
    Netherlands,
    Hungary,
    Poland,
    Switzerland,
    Belgium,
    France,
    Germany,
    Spain,
    Portugal,
    Canada,
    United_States,
    Mexico,
    South_Africa,
    Brazil,
    Argentina,
    Peru,
    Chile,
    Uruguay,
};

class Team;

class Player
{
private:
    // Player
    // int id_;
    std::string nickname_;

    // Bio and personal data
    // unsigned int age_;
    // DATE birth;
    std::string firstName_;
    std::string lastName_;
    std::string name_;
    Country country_;

    // Team
    Team *pTeam_;
    int position_;
    bool isActive_;
    bool isCaptain_;
    bool isCoach_;

    int power_;
    int kills_;
    int deaths_;

    int matchesPlayed_;
    int matchesWon_;
    int matchesLost_;

    void setTeam(Team *);

    void setPosition(const int &);

    void setActive();
    void setInactive();

    void setPower(const int &);

    void setKills(const int &);
    void setDeaths(const int &);

    void setMatchesPlayed(const int &);
    void setMatchesWon(const int &);
    void setMatchesLost(const int &);

public:
    friend class Team;

    Player(const std::string &, const Country &);
    ~Player();

    void setNickname(const std::string &);
    std::string getNickname() const;

    void setName(const std::string &);
    std::string getName() const;

    void setCountry(const Country &);
    Country getCountry() const;

    // void setAge(const unsigned int &);
    // unsigned int getAge() const;

    Team *getTeam() const;

    int getPosition() const;

    bool isActive() const;
    bool isCaptain() const;
    bool isCoach() const;

    int getPower() const;
    int getKills() const;
    int getDeaths() const;
    int getMatchesPlayed() const;
    int getMatchesWon() const;
    int getMatchesLost() const;

    // void Serialize();
    // void kill(Player *);
};

// Constructor
Player::Player(const std::string &nickname, const Country &country)
{
    // id_ = id;
    nickname_ = nickname;
    country_ = country;
    pTeam_ = nullptr;
    position_ = 0;
    isActive_ = false;
    isCaptain_ = false;
    isCoach_ = false;
    matchesPlayed_ = 0;
    matchesWon_ = 0;
    matchesLost_ = 0;
    kills_ = 0;
    deaths_ = 0;
}

// Destructor
Player::~Player() = default;

void Player::setNickname(const std::string &nickname)
{
    nickname_ = nickname;
}

std::string Player::getNickname() const
{
    return nickname_;
}

void Player::setCountry(const Country &country)
{
    country_ = country;
}

Country Player::getCountry() const
{
    return country_;
}

// void Player::setAge(const int &age)
// {
//     age_ = age;
// }

// int Player::getAge() const
// {
//     return age_;
// }

void Player::setTeam(Team *pTeam)
{
    pTeam_ = pTeam;
}

Team *Player::getTeam() const
{
    return pTeam_;
}

void Player::setPosition(const int &position)
{
    position_ = position;
}

int Player::getPosition() const
{
    return position_;
}

void Player::setActive()
{
    isActive_ = true;
}

void Player::setInactive()
{
    isActive_ = false;
}

bool Player::isActive() const
{
    return isActive_;
}

bool Player::isCaptain() const
{
    return isCaptain_;
}

bool Player::isCoach() const
{
    return isCoach_;
}

void Player::setPower(const int &power)
{
    power_ = power;
}

int Player::getPower() const
{
    return matchesLost_;
}

void Player::setKills(const int &kills)
{
    kills_ = kills;
}

int Player::getKills() const
{
    return kills_;
}

void Player::setDeaths(const int &deaths)
{
    deaths_ = deaths;
}

int Player::getDeaths() const
{
    return deaths_;
}

void Player::setMatchesPlayed(const int &matchesPlayed)
{
    matchesPlayed_ = matchesPlayed;
}

int Player::getMatchesPlayed() const
{
    return matchesPlayed_;
}

void Player::setMatchesWon(const int &matchesWon)
{
    matchesWon_ = matchesWon;
}

int Player::getMatchesWon() const
{
    return matchesWon_;
}

void Player::setMatchesLost(const int &matchesLost)
{
    matchesLost_ = matchesLost;
}

int Player::getMatchesLost() const
{
    return matchesLost_;
}

// void Player::kill(Player *player)
// {
//     kills_++;
//     player->deaths_++;
// }
