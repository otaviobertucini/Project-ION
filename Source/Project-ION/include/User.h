#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User
{
public:
    User();
    User(string name, float score = 0);
    ~User();
    void setScore(float score);
    string getName();
    float getScore();

private:

    string name;
    float score;
};

#endif // USER_H
