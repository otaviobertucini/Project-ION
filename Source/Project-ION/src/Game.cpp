#include "Game.h"

Game::Game()
{
    images = new Images;
    levels = new List_Levels;
    menu1 = new Menu(buffer);
}

Game::~Game()
{
    delete images;
    images = NULL;
    destroy_bitmap(buffer);
    current = NULL;
}
