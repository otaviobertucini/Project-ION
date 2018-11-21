#ifndef LIST_LEVELS_H
#define LIST_LEVELS_H
#include "Level.h"
#include <vector>

class List_Levels
{
public:
    List_Levels();
    void include(Level* newl);
    void deleteAll();
    int size();
    void eraseAll();
    Level* operator[](int index);
    virtual ~List_Levels();
private:
    std::vector<Level*> levels;
};

#endif // LIST_LEVELS_H
