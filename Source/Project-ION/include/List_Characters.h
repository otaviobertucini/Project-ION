#ifndef LIST_CHARACTERS_H
#define LIST_CHARACTERS_H
#include "Character.h"

class List_Characters
{
public:
    List_Characters();
    void include(Character* newc);
    void deleteAll();
    int empty();
    int size();
    Character* operator[](int index);
    virtual ~List_Characters();
private:
    std::vector<Character*> characters;
};

#endif // LIST_CHARACTERS_H
