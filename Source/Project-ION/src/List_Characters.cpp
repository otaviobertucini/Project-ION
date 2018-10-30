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

void List_Characters::deleteAll(){
    typename std::vector<Character*>::iterator itr = characters.begin();
    for(; itr != characters.end(); itr++)
        delete *itr;
    characters.clear();
}

List_Characters::~List_Characters()
{
    //dtor
}
