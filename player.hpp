#pragma once
#include <chrono>
#include <string>
#include <vector>
#include <list>

using namespace std::chrono;
using std::string, std::vector, std::list;

enum Lane
{
    Easy,
    Mid,
    Hard
};

enum RoleMOBA
{
    Core,
    Support
};

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
    unsigned long long int id_;
    string nickname_;

    // Bio and personal data
    unsigned int age_;
    string firstName_;
    string lastName_;
    string name_;
    Country country_;

    // Team
    Team *pTeam_;
    int position_;
    bool isActive_;
    bool isCaptain_;
    // bool isSniper_;
    // bool isEntry_;
    bool isCoach_;

    // Stats
    unsigned int power_;
    unsigned long long int kills_;
    unsigned long long int deaths_;
    unsigned long long int matchesPlayed_;
    unsigned long long int matchesWon_;
    unsigned long long int matchesLost_;

public:
    // Player();
    Player(/*const unsigned long long int &, */ const string &, const Country &, Team *);
    ~Player();

    // Setters
    void setNickname(const string &);
    void setName(const string &);
    void setCountry(const Country &);
    void setAge(const unsigned int &);
    void setTeam(Team *);
    void setPosition(const int &);
    void setActive();
    void setInactive();
    void setPower(const unsigned int &);
    void setKills(const unsigned long long int &);
    void setDeaths(const unsigned long long int &);
    void setMatchesPlayed(const unsigned long long int &);
    void setMatchesWon(const unsigned long long int &);
    void setMatchesLost(const unsigned long long int &);

    // Getters
    string getNickname() const;
    string getName() const;
    Country getCountry() const;
    unsigned int getAge() const;
    Team *getTeam() const;
    int getPosition() const;
    unsigned int getPower() const;
    unsigned long long int getKills() const;
    unsigned long long int getDeaths() const;
    unsigned long long int getMatchesPlayed() const;
    unsigned long long int getMatchesWon() const;
    unsigned long long int getMatchesLost() const;

    // void Serialize();
    // void kill(Player *);
};

// Constructor
Player::Player(/*const unsigned int &id, */ const string &nickname, const Country &country, Team *pTeam = nullptr)
{
    // id_ = id;
    nickname_ = nickname;
    country_ = country;
    pTeam_ = pTeam;
    matchesPlayed_ = 0;
    matchesWon_ = 0;
    matchesLost_ = 0;
    kills_ = 0;
    deaths_ = 0;
}

// Destructor
Player::~Player() = default;

void Player::setNickname(const string &nickname)
{
    nickname_ = nickname;
}

string Player::getNickname() const
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

void Player::setAge(const unsigned int &age)
{
    age_ = age;
}

unsigned int Player::getAge() const
{
    return age_;
}

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

void Player::setPower(const unsigned int &power)
{
    power_ = power;
}

unsigned int Player::getPower() const
{
    return matchesLost_;
}

void Player::setKills(const unsigned long long int &kills)
{
    kills_ = kills;
}

unsigned long long int Player::getKills() const
{
    return kills_;
}

void Player::setDeaths(const unsigned long long int &deaths)
{
    deaths_ = deaths;
}

unsigned long long int Player::getDeaths() const
{
    return deaths_;
}

void Player::setMatchesPlayed(const unsigned long long int &matchesPlayed)
{
    matchesPlayed_ = matchesPlayed;
}

unsigned long long int Player::getMatchesPlayed() const
{
    return matchesPlayed_;
}

void Player::setMatchesWon(const unsigned long long int &matchesWon)
{
    matchesWon_ = matchesWon;
}

unsigned long long int Player::getMatchesWon() const
{
    return matchesWon_;
}

void Player::setMatchesLost(const unsigned long long int &matchesLost)
{
    matchesLost_ = matchesLost;
}

unsigned long long int Player::getMatchesLost() const
{
    return matchesLost_;
}

// void Player::kill(Player *player)
// {
//     kills_++;
//     player->deaths_++;
// }
