#ifndef LIST_OBSTACLES_H
#define LIST_OBSTACLES_H
#include <vector>
#include "Obstacle.h"

class List_Obstacles
{
public:
    List_Obstacles();
    void include(Obstacle* newc);
    void deleteAll();
    int empty();
    int size();
    void eraseAll();
    Obstacle* operator[](int index);
    virtual ~List_Obstacles();
private:
    std::vector<Obstacle*> obstacles;
};

#endif // LIST_OBSTACLES_H
