#include "List_Poisons.h"

List_Poisons::List_Poisons()
{
    //ctor
}

void List_Poisons::include(Poison* newl){
    poisons.push_back(newl);
}

int List_Poisons::size(){
    return poisons.size();
}

void List_Poisons::eraseAll(){
    for(int i = 0; i < size(); i++){
        delete poisons.at(i);
    }
    poisons.clear();
}

void List_Poisons::loop(){
    for(int i = 0; i < size(); i++){
        poisons.at(i)->loop();
    }
}

void List_Poisons::print(BITMAP* buffer){
    for(int i = 0; i < size(); i++){
        poisons.at(i)->print(buffer);
    }
}

Poison* List_Poisons::operator[](int index){
    return poisons.at(index);
}

void List_Poisons::del(int i){
    poisons.erase(poisons.begin() + i);
}

int List_Poisons::isCollide(Human* a){
    for(int i = 0; i < size(); i++){
        int x_sum = (a->getw()/2)+(poisons.at(i)->getw()/2);
        int y_sum = (a->geth()/2)+(poisons.at(i)->geth()/2);
        if((abs((a->getx()+(a->getw()/2)) - (poisons.at(i)->getx()+(poisons.at(i)->getw()/2))) <= x_sum) &&
            (abs((a->gety()+(a->geth()/2)) - (poisons.at(i)->gety()+(poisons.at(i)->geth()/2))) <= y_sum )){
        return 1;
        }
    }
    return 0;
}

List_Poisons::~List_Poisons()
{
    //dtor
}
