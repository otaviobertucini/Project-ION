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
