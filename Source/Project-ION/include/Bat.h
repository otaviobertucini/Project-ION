#ifndef BAT_H
#define BAT_H
#include <Enemy.h>

class Bat: public Enemy
{
public:
    Bat();
    Bat(float x, float y, List_Images *img, int direction = 1, int step = 1,int x_distance = 40, int y_distance = 30, float flew = 0);
    void loop();
    void move(int x_move);
    const int getyInitial() const;
    void saveState(std::ofstream& myfile);
    virtual ~Bat();
private:
    float flew;
    int step;
    int x_distance;
    int y_distance;
};

#endif // BAT_H
