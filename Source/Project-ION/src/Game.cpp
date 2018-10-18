#include "Game.h"

Game::Game()
{}

Game::~Game()
{
    delete images;
    images = NULL;
    destroy_bitmap(buffer);
    current = NULL;

    std::vector<Level*>::iterator itr = levels.begin();
    for(itr; itr != levels.end(); itr++)
        delete *itr;
    levels.clear();

    std::vector<Map*>::iterator itr2 = maps.begin();
    for(itr2; itr2 != maps.end(); itr2++)
        delete *itr2;
    maps.clear();
}
