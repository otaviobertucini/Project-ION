#include "User.h"

User::User()
{
    name = " ";
    score = 0;
    level = 0;
}

User::User(string name, int score, int level)
{
    this->name = name;
    this->score = score;
    this->level = level;
}

void User::setAll(string newName, int score, int level)
{
    name = newName;
    this->score = score;
    this->level = level;
}

void User::setName(const string newName)
{
    name = newName;
}

void User::setScore(const int score)
{
    this->score = score;
}

void User::setLevel(const int level)
{
    this->level = level;
}

const string User::getName() const
{
    return name;
}

const int User::getScore() const
{
    return score;
}

const int User::getLevel() const
{
    return level;
}

User::~User()
{
}
