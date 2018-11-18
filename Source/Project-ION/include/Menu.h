#ifndef MENU_H
#define MENU_H
#include <allegro.h>
#include <iostream>
#include <string>
#include "List_User.h"

using namespace std;

class Menu
{
public:
    Menu();
    Menu(BITMAP* buffer);
    int inicial();
    int pause();
    int sologame();
    string readMenu();
    void ranking();
    virtual ~Menu();
private:
    BITMAP* buffer;
    BITMAP* img_back;
    BITMAP* cursor;
    BITMAP* pause_back;
    BITMAP* solo_back;
    BITMAP* login_back;
    BITMAP* rank_back;
    FONT* font_main;
};

#endif // MENU_H
