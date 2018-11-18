#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User
{
public:
    User();
    User(string name, float score = 0, int level = 0);
    ~User();
    void setAll(string newName, float score = 0, int level = 0);
    void setName(string newName);
    void setScore(float score);
    void setLevel(int level);
    string getName();
    float getScore();
    int getLevel();

private:

    string name;
    float score;
    int level;
};

#endif // USER_H
