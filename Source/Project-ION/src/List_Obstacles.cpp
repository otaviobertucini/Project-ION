#include "List_Obstacles.h"

List_Obstacles::List_Obstacles()
{
    //ctor
}

void List_Obstacles::include(Obstacle* news){
    obstacles.push_back(news);
}

int List_Obstacles::empty(){
    return obstacles.empty();
}

int List_Obstacles::size(){
    return obstacles.size();
}

Obstacle* List_Obstacles::operator[](int index){
    return obstacles[index];
}

void List_Obstacles::eraseAll(){
    obstacles.erase(obstacles.begin(), obstacles.end());
}

void List_Obstacles::deleteAll(){
    typename std::vector<Obstacle*>::iterator itr = obstacles.begin();
    for(; itr != obstacles.end(); itr++)
        delete *itr;
    obstacles.clear();
}

List_Obstacles::~List_Obstacles()
{
    //dtor
}
