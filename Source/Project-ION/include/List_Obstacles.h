#ifndef LIST_OBSTACLES_H
#define LIST_OBSTACLES_H
#include <vector>
#include "Obstacle.h"
#include "Character.h"
#include "List_Characters.h"

class List_Obstacles
{
public:
    List_Obstacles();
    void include(Obstacle* newc);
    void deleteAll();
    int empty();
    int size();
    void eraseAll();
    int isCollide(Character* a);
    int isCollide(List_Characters* chars);
    void print(BITMAP* buffer);
    virtual ~List_Obstacles();
private:
    std::vector<Obstacle*> obstacles;
};

#endif // LIST_OBSTACLES_H
