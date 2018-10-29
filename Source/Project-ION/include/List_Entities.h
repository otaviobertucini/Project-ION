#ifndef LIST_ENTITIES_H
#define LIST_ENTITIES_H
#include "List.h"
#include "Entity.h"

class List_Entities
{
public:
    List_Entities();
    virtual ~List_Entities();
private:
    List<Entity*> structures;
};

#endif // LIST_ENTITIES_H
