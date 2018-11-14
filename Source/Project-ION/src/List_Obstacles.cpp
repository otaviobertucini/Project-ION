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

void List_Obstacles::eraseAll(){
    obstacles.erase(obstacles.begin(), obstacles.end());
}

int List_Obstacles::isCollide(Character* a){
    for(int i = 0; i < size(); i++){
        int x_sum = (a->getw()/2)+(obstacles[i]->getw()/2);
        int y_sum = (a->geth()/2)+(obstacles[i]->geth()/2);
        if((abs((a->getx()+(a->getw()/2)) - (obstacles[i]->getx()+(obstacles[i]->getw()/2))) <= x_sum) &&
            (abs((a->gety()+(a->geth()/2)) - (obstacles[i]->gety()+(obstacles[i]->geth()/2))) <= y_sum )){
        return 1;
        }
    }
    return 0;
}

int List_Obstacles::isCollide(List_Characters* chars){
    for(int i = 0; i < chars->size(); i++){
        if(isCollide((*chars)[i])){
            delete (*chars)[i];
            chars->erase(i);
        }
    }
}

void List_Obstacles::print(BITMAP* buffer){
    for(int i = 0; i < size(); i++){
        obstacles[i]->print(buffer);
    }
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
