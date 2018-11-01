#ifndef MENU_H
#define MENU_H
#include <allegro.h>
#include <iostream>
using std::cout;
using std::endl;

class Menu
{
public:
    Menu();
    Menu(BITMAP* buffer);
    int inicial();
    int pause();
    virtual ~Menu();
private:
    BITMAP* buffer;
    BITMAP* img_back;
    BITMAP* cursor;
    BITMAP* pause_back;
};

#endif // MENU_H
