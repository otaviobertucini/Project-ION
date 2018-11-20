#include "List_Images.h"

List_Images::List_Images()
{}

void List_Images::include(BITMAP* newi){
    Images_Library.push_back(newi);
}

int List_Images::empty(){
    return Images_Library.empty();
}

int List_Images::size(){
    return Images_Library.size();
}

BITMAP* List_Images::operator[](int index){
    return Images_Library[index];
}

void List_Images::deleteAll(){
    for(int i = 0; i < size(); i++){
        destroy_bitmap(Images_Library[i]);
        Images_Library[i] = NULL;
    }
    Images_Library.clear();
}

List_Images::~List_Images()
{
    deleteAll();
}
