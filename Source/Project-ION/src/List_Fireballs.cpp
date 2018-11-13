#include "List_Fireballs.h"

List_Fireballs::List_Fireballs()
{
    //ctor
}

void List_Fireballs::include(Fireball* news){
    fireballs.push_back(news);
}

int List_Fireballs::empty(){
    return fireballs.empty();
}

int List_Fireballs::size(){
    return fireballs.size();
}

Fireball* List_Fireballs::operator[](int index){
    return fireballs[index];
}

void List_Fireballs::erase(int i){
    fireballs.erase(fireballs.begin() + i);
}

void List_Fireballs::eraseAll(){
    for(unsigned int i = 0; i<fireballs.size(); i++){
        delete fireballs[i];
        fireballs[i] = NULL;
    }
    fireballs.clear();
}

void List_Fireballs::deleteAll(){
    for(int i = 0; i<fireballs.size(); i++){
        delete fireballs[i];
        fireballs[i] = NULL;
    }
    fireballs.clear();
}

List_Fireballs::~List_Fireballs()
{
    //dtor
}
