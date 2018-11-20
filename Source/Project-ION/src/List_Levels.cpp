#include "List_Levels.h"

List_Levels::List_Levels()
{
    //ctor
}

void List_Levels::include(Level* news){
    levels.push_back(news);
}

int List_Levels::size(){
    return levels.size();
}

Level* List_Levels::operator[](int index){
    return levels[index];
}

void List_Levels::eraseAll(){
    for(int i = 0; i  < size(); i++){
        levels[i]->eraseAll();
    }
}

void List_Levels::deleteAll(){
    for(int i = 0; i < size(); i++){
        delete levels[i];
        levels[i] = NULL;
    }
}

List_Levels::~List_Levels()
{
    deleteAll();
}
