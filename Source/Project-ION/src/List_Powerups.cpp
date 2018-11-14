#include "List_Powerups.h"

List_Powerups::List_Powerups()
{
    //ctor
}

void List_Powerups::include(Powerup* newp){
    powers.push_back(newp);
}

int List_Powerups::empty(){
    return powers.empty();
}

int List_Powerups::size(){
    return powers.size();
}

Powerup* List_Powerups::operator[](int index){
    return powers[index];
}

int List_Powerups::isCollide(Human* a){
    for(int i = 0; i < size(); i++){
        int x_sum = (a->getw()/2)+(powers[i]->getw()/2);
        int y_sum = (a->geth()/2)+(powers[i]->geth()/2);
        if((abs((a->getx()+(a->getw()/2)) - (powers[i]->getx()+(powers[i]->getw()/2))) <= x_sum) &&
            (abs((a->gety()+(a->geth()/2)) - (powers[i]->gety()+(powers[i]->geth()/2))) <= y_sum )){
            powers[i]->modify(a);
            a->turnPowerup();
            delete powers[i];
            erase(i);
            return 1;
        }
    }
    return 0;
}

void List_Powerups::print(BITMAP* buffer){
    for(int i = 0; i < size(); i++){
        powers[i]->print(buffer);
    }
}

void List_Powerups::erase(int i){
    powers.erase(powers.begin() + i);
}

void List_Powerups::eraseAll(){
    for(unsigned int i = 0; i<powers.size(); i++){
        delete powers[i];
        powers[i] = NULL;
    }
    powers.clear();
}

void List_Powerups::deleteAll(){
    for(int i = 0; i<powers.size(); i++){
        delete powers[i];
        powers[i] = NULL;
    }
    powers.clear();
}

List_Powerups::~List_Powerups()
{
    //dtor
}
