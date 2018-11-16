#include "User.h"

User::User()
{
}

User::User(string name, float score)
{
    this->name = name;
    this->score = score;
}

void User::setScore(float score)
{
    this->score = score;
}

void User::setName(string name)
{
    this->name = name;
}

string User::getName()
{
    return name;
}

float User::getScore()
{
    return score;
}

User::~User()
{
}
