#include "List_Fireballs.h"

List_Fireballs::List_Fireballs()
{
    //ctor
}

void List_Fireballs::include(Fireball* news){
    fireballs.push_back(news);
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

int List_Fireballs::isCollide(Human* a){
    for(int i = 0; i < size(); i++){
        int x_sum = (a->getw()/2)+(fireballs[i]->getw()/2);
        int y_sum = (a->geth()/2)+(fireballs[i]->geth()/2);
        if((abs((a->getx()+(a->getw()/2)) - (fireballs[i]->getx()+(fireballs[i]->getw()/2))) <= x_sum) &&
            (abs((a->gety()+(a->geth()/2)) - (fireballs[i]->gety()+(fireballs[i]->geth()/2))) <= y_sum )){
        return 1;
        }
    }
    return 0;
}

void List_Fireballs::print(BITMAP* buffer){
    for(int i = 0; i < size(); i++){
        fireballs[i]->print(buffer);
    }
}

void List_Fireballs::loop(){
    for(int i = 0; i < size(); i++){
        fireballs[i]->loop();
    }
}

void List_Fireballs::eraseAll(){
    for(unsigned int i = 0; i<fireballs.size(); i++){
        delete fireballs[i];
        fireballs[i] = NULL;
    }
    fireballs.clear();
}

void List_Fireballs::saveLevel(std::ofstream& myfile){
    for(int i = 0; i < size(); i++){
        fireballs[i]->saveState(myfile);
    }
}

List_Fireballs::~List_Fireballs()
{
    //dtor
}
