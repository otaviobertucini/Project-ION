#ifndef MAIN_H
#define MAIN_H
#include <allegro.h>
#include "SoloGame.h"
#include "Menu.h"

class Main
{
public:
    Main();
    void execute();
    virtual ~Main();
private:
    Menu* menu;
    bool exit;
    SoloGame* solo;
    BITMAP* buffer;
};

#endif // MAIN_H
