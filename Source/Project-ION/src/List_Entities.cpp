#include "List_Entities.h"

List_Entities::List_Entities()
{
    //ctor
}

void List_Entities::include(Entity* news){
    entities.push_back(news);
}

int List_Entities::empty(){
    return entities.empty();
}

int List_Entities::size(){
    return entities.size();
}

Entity* List_Entities::operator[](int index){
    return entities[index];
}

void List_Entities::deleteAll(){
    typename std::vector<Entity*>::iterator itr = entities.begin();
    for(; itr != entities.end(); itr++)
        delete *itr;
    entities.clear();
}

List_Entities::~List_Entities()
{
    deleteAll();
}
