#include "List_Structures.h"

List_Structures::List_Structures()
{
    //ctor
}

void List_Structures::include(Structure* news){
    structures.push_back(news);
}

int List_Structures::empty(){
    return structures.empty();
}

int List_Structures::size(){
    return structures.size();
}

void List_Structures::print(BITMAP* buffer){
    for(int i = 0; i < size(); i++){
        structures[i]->print(buffer);
    }
}

int List_Structures::isCollide(Moveable* a){
    int i;
    float x_center,y_center,x_center_body,y_center_body;

    x_center = a->getx()+(a->getw()/2);
    y_center = a->gety()+(a->geth()/2);

    a->setLeft(true);
    a->setRight(true);
    a->setUp(true);
    a->setDown(true);

    for(i=0; i < size(); i++)
    {
        x_center_body = structures[i]->getx() + 15;
        y_center_body = structures[i]->gety() + 15;

        //emcima do 2
        if(a->gety() + a->geth() >= structures[i]->gety() && y_center <= y_center_body
           && abs(x_center - x_center_body) < (a->getw()/2)+(structures[i]->getw()/2)-2)
        {
            a->setDown(false);
            a->sety(structures[i]->gety() - a->geth());
        }
        //embaixo do 2
        if(a->gety() <= structures[i]->gety() + structures[i]->geth() && y_center >= y_center_body
           && abs(x_center - x_center_body) < (a->getw()/2)+(structures[i]->getw()/2)-2)
        {
            a->setUp(false);
        }
        //esquerda do 2
        if(a->getx() + a->getw() >= structures[i]->getx() && x_center <= x_center_body
                && abs(y_center - y_center_body) < (a->geth()/2)+(structures[i]->geth()/2)-2){
            a->setRight(false);
        }
        //direita do 2
        if(a->getx() <= structures[i]->getx() + structures[i]->getw() && x_center >= x_center_body
                && abs(y_center - y_center_body) < (a->geth()/2)+(structures[i]->geth()/2)-2){
            a->setLeft(false);
        }
    }
}

int List_Structures::isCollide(List_Characters* chars){
    for(int i = 0; i < chars->size(); i++){
        isCollide(static_cast<Moveable*>((*chars)[i]));
    }
}

int List_Structures::isCollide(List_Fireballs* fires){
    for(int i = 0; i < fires->size(); i++){
        isCollide(static_cast<Moveable*>((*fires)[i]));
        if(!(*fires)[i]->getMoveUp()){
            delete (*fires)[i];
            fires->erase(i);
        }
    }
}

int List_Structures::isCollide(List_Poisons* poisons){
    for(int i = 0; i < poisons->size(); i++){
        isCollide(static_cast<Moveable*>((*poisons)[i]));
        if(!(*poisons)[i]->getMoveSide()){
            delete (*poisons)[i];
            poisons->del(i);
            return 1;
        }
    }
    return 0;
}

Structure* List_Structures::operator[](int index){
    return structures[index];
}

void List_Structures::deleteAll(){
    structures.erase(structures.begin(), structures.end());
}

List_Structures::~List_Structures()
{
    //dtor
}
