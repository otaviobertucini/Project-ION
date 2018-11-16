#include "User.h"

User::User()
{
    name = " ";
    score = 0;
}

User::User(string name, float score)
{
    int i=0;
    while(name[i]!=NULL)
    {
        this->name[i]=name[i];
        i++;
    }

    this->score = score;
}

void User::setScore(float score)
{
    this->score = score;
}

void User::setName(string newName)
{
    name = newName;
    int i=0;

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
