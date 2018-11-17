#include "User.h"

User::User()
{
    name = " ";
    score = 0;
    level = 0;
}

User::User(string name, float score, int level)
{
    this->name = name;
    this->score = score;
    this->level = level;
}

void User::setAll(string name, float score, int level)
{
    this->name = name;
    this->score = score;
    this->level = level;
}

void User::setName(string newName)
{
    name = newName;
}

void User::setScore(float score)
{
    this->score = score;
}

void User::setLevel(int level)
{
    this->level = level;
}

string User::getName()
{
    return name;
}

float User::getScore()
{
    return score;
}

int User::getLevel()
{
    return level;
}

User::~User()
{
}
