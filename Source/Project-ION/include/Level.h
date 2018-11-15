#ifndef LEVEL_H
#define LEVEL_H
#include <allegro.h>
#include <cstddef> //library for NULL
#include <iostream>
#include <vector>
#include <fstream>
#include "Map.h"
#include "Character.h"
#include "Topspin.h"
#include "Bat.h"
#include "Human.h"
#include "List_Images.h"
#include "Entity.h"
#include "Moveable.h"
#include "List_Characters.h"
#include "List_Lavas.h"
#include "List_Powerups.h"
#include "List_Fireballs.h"
#include "List_Obstacles.h"
#include "List_Structures.h"
#include "Images.h"
using std::cout;
using std::endl;

class Level
{
public:
    Level();
    Level(BITMAP* buffer, Images *images, Human* jack);
    virtual ~Level();
    void printMap();
    int getValueMap(int i, int j);
    float getXInitial();
    float getYInitial();
    void generateMap(int** matrix);
    int isCollide(Entity* a, Entity* b);
    void isStructureCollide(Moveable* a);
    int isFireballCollide(Character* a);
    int isPowerupCollide(Human* a);
    List_Characters* getListCharacters();
    List_Powerups* getListPowerups();
    List_Fireballs* getListFireballs();
    int genericGameLoop();
    virtual int gameLoop() = 0;
    virtual void generateLevel() = 0;
    virtual void resetLevel();
    virtual void eraseAll();
    virtual void resetPlayer();
    virtual void resetPlayer(float x, float y);
    virtual void saveLevel(std::ofstream& myfile);
    virtual void loadLevel(ifstream& file);
protected:
    BITMAP* buffer; //Pointer to the display where all components will be shown.
    Human* jack;
    List_Characters* characters;
    Images* images;
    float x_initial;
    float y_initial;
    int game_status;
    int was_genereted;
    List_Obstacles* obstacles;
    List_Structures* structures;
    List_Lavas* lavas;
    int iterations;
    FONT* font_main;
};

#endif // LEVEL_H
