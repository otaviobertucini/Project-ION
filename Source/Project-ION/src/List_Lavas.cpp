#include "List_Lavas.h"

List_Lavas::List_Lavas()
{
    //ctor
}

void List_Lavas::include(Lava* newl){
    lavas.push_back(newl);
}

int List_Lavas::empty(){
    return lavas.empty();
}

int List_Lavas::size(){
    return lavas.size();
}

Lava* List_Lavas::operator[](int index){
    return lavas[index];
}

void List_Lavas::eraseAll(){
    lavas.erase(lavas.begin(), lavas.end());
}

void List_Lavas::deleteAll(){
    typename std::vector<Lava*>::iterator itr = lavas.begin();
    for(; itr != lavas.end(); itr++)
        delete *itr;
    lavas.clear();
}

List_Lavas::~List_Lavas()
{
    //dtor
}
