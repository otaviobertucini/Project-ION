#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User
{
public:
    User();
    User(string name, int score = 0, int level = 0);
    ~User();
    void setAll(string newName, int score = 0, int level = 0);
    void setName(const string newName);
    void setScore(const int score);
    void setLevel(const int level);
    const string getName() const;
    const int getScore() const;
    const int getLevel() const;
private:
    string name;
    int score;
    int level;
};

#endif // USER_H
