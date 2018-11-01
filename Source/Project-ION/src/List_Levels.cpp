#include "List_Levels.h"

List_Levels::List_Levels()
{
    //ctor
}

void List_Levels::include(Level* news){
    levels.push_back(news);
}

int List_Levels::empty(){
    return levels.empty();
}

int List_Levels::size(){
    return levels.size();
}

Level* List_Levels::operator[](int index){
    return levels[index];
}

void List_Levels::eraseAll(){
    levels.erase(levels.begin(), levels.end());
}

void List_Levels::deleteAll(){
    typename std::vector<Level*>::iterator itr = levels.begin();
    for(; itr != levels.end(); itr++)
        delete *itr;
    levels.clear();
}

List_Levels::~List_Levels()
{
    deleteAll();
}
