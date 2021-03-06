#ifndef LIST_CHARACTERS_H
#define LIST_CHARACTERS_H
#include "Character.h"
#include "Human.h"

class List_Characters
{
public:
    List_Characters();
    void include(Character* newc);
    int size();
    void erase(int i);
    void eraseAll();
    void print(BITMAP* buffer);
    void loop();
    int isCollide(Human* a);
    void saveLevel(std::ofstream& myfile);
    Character* operator[](int index);
    virtual ~List_Characters();
private:
    std::vector<Character*> characters;
};

#endif // LIST_CHARACTERS_H
