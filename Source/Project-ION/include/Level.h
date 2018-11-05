#ifndef LEVEL_H
#define LEVEL_H
#include <allegro.h>
#include <cstddef> //library for NULL
#include <iostream>
#include <vector>
#include "Map.h"
#include "Character.h"
#include "Human.h"
#include "List_Images.h"
#include "Entity.h"
#include "List_Characters.h"
#include "List_Lavas.h"
#include "Images.h"
using std::cout;
using std::endl;

class Level
{
public:
    Level();
    Level(BITMAP* buffer, Images *images, Human* jack);
    virtual ~Level();
    Map* getMap();
    void printMap();
    void updatePosition();
    int getValueMap(int i, int j);
    float getXInitial();
    float getYInitial();
    int isCollide(Entity* a, Entity* b);
    void isStructureCollide(Character* a);
    void loopCharacters();
    void collisionCharacters();
    int isCharacterCollide(Character* a);
    int isObstacleCollide(Character* a);
    int isFireballCollide(Character* a);
    List_Characters* getListCharacters();
    int genericGameLoop();
    virtual int gameLoop() = 0;
    virtual void generateLevel() = 0;
    virtual void generateLevel(List_Characters* characters) = 0;
    virtual void startLevel() = 0;
    virtual void resetLevel();
    void eraseAll();
    virtual void resetPlayer();
    virtual void resetPlayer(float x, float y);
    void loopFireballs();
protected:
    Map* map; //Pointer to the level map.
    BITMAP* buffer; //Pointer to the display where all components will be shown.
    Human* jack;
    List_Characters* characters;
    Images* images;
    float x_initial;
    float y_initial;
    int game_status;
    int was_genereted;
    List_Lavas* lavas;
    std::vector<Fireball*> fireballs;
};

#endif // LEVEL_H
