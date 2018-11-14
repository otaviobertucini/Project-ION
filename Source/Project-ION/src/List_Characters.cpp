#include "List_Characters.h"

List_Characters::List_Characters()
{
    //ctor
}

void List_Characters::include(Character* news){
    characters.push_back(news);
}

int List_Characters::empty(){
    return characters.empty();
}

int List_Characters::size(){
    return characters.size();
}

void List_Characters::erase(int i){
    characters.erase(characters.begin() + i);
}

void List_Characters::eraseAll(){
    for(unsigned int i = 0; i<characters.size(); i++){
        delete characters[i];
        characters[i] = NULL;
    }
    characters.clear();
}

void List_Characters::print(BITMAP* buffer){
    for(int i = 0; i < size(); i++){
        characters[i]->print(buffer);
    }
}

void List_Characters::loop(){
    for(int i = 0; i < size(); i++){
        characters[i]->loop();
    }
}

int List_Characters::isCollide(Human* a){
    if(!a->isPowered()){
        for(int i = 0; i < size(); i++){
            int x_sum = (a->getw()/2)+(characters[i]->getw()/2);
            int y_sum = (a->geth()/2)+(characters[i]->geth()/2);
            if((abs((a->getx()+(a->getw()/2)) - (characters[i]->getx()+(characters[i]->getw()/2))) <= x_sum) &&
                (abs((a->gety()+(a->geth()/2)) - (characters[i]->gety()+(characters[i]->geth()/2))) <= y_sum )){
            return 1;
            }
        }
    }
    return 0;
}

Character* List_Characters::operator[](int index){
    return characters[index];
}

void List_Characters::deleteAll(){
    for(int i = 0; i<characters.size(); i++){
        delete characters[i];
        characters[i] = NULL;
    }
    characters.clear();
}

List_Characters::~List_Characters()
{
    //dtor
}
