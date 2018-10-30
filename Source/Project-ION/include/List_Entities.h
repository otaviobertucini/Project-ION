#ifndef LIST_ENTITIES_H
#define LIST_ENTITIES_H
#include <vector>
#include "Entity.h"

class List_Entities
{
public:
    List_Entities();
    void include(Entity* news);
    void deleteAll();
    int empty();
    int size();
    Entity* operator[](int index);
    virtual ~List_Entities();
private:
    std::vector<Entity*> entities;
};

#endif // LIST_ENTITIES_H
