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

Character* List_Characters::operator[](int index){
    return characters[index];
}

void List_Characters::erase(int i){
    characters.erase(characters.begin() + i);
}

void List_Characters::eraseAll(){
    characters.erase(characters.begin(), characters.end());
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
