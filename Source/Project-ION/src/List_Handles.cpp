#include "List_Handles.h"

List_Handles::List_Handles()
{
    //ctor
}

void List_Handles::include(Handle* newl){
    handles.include(newl);
}

int List_Handles::size(){
    return handles.size();
}

void List_Handles::eraseAll(){
    for(int i = 0; i < size(); i++){
        delete handles.at(i);
    }
    handles.clear();
}

void List_Handles::print(BITMAP* buffer){
    for(int i = 0; i < size(); i++){
        handles.at(i)->print(buffer);
    }
}

Handle* List_Handles::isCollide(Human* a){
    if(!a->isPowered()){
        for(int i = 0; i < size(); i++){
            int x_sum = (a->getw()/2)+(handles.at(i)->getw()/2);
            int y_sum = (a->geth()/2)+(handles.at(i)->geth()/2);
            if((abs((a->getx()+(a->getw()/2)) - (handles.at(i)->getx()+(handles.at(i)->getw()/2))) <= x_sum) &&
                (abs((a->gety()+(a->geth()/2)) - (handles.at(i)->gety()+(handles.at(i)->geth()/2))) <= y_sum )){
            return handles.at(i);
            }
        }
    }
    return NULL;
}

List_Handles::~List_Handles()
{
    //dtor
}
