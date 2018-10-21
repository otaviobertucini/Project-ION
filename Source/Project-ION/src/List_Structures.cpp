#include "List_Structures.h"

List_Structures::List_Structures()
{
    //ctor
}

void List_Structures::include(Structure* news){
    structures.include(news);
}

int List_Structures::empty(){
    return structures.empty();
}

int List_Structures::size(){
    return structures.size();
}

Structure* List_Structures::operator[](int index){
    return structures[index];
}

void List_Structures::deleteAll(){
    structures.deleteAll();
}

List_Structures::~List_Structures()
{
    //dtor
}
