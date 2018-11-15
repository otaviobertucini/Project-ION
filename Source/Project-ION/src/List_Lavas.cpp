#include "List_Lavas.h"

List_Lavas::List_Lavas()
{
    //ctor
}

void List_Lavas::include(Lava* newl){
    lavas.include(newl);
}

int List_Lavas::size(){
    return lavas.size();
}

void List_Lavas::createFireballs(List_Fireballs* fires){
    for(int i = 0; i < size(); i++){
        Fireball* fire = lavas.at(i)->createFireball();
        if(fire != NULL){
            fires->include(fire);
        }
    }
}

void List_Lavas::eraseAll(){
    for(int i = 0; i < size(); i++){
        delete lavas.at(i);
    }
    lavas.clear();
}

List_Lavas::~List_Lavas()
{
    //dtor
}
