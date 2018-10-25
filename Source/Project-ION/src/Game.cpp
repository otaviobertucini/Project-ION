#include "Game.h"

Game::Game()
{
    allegro_init();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1080, 720, 0, 0);
}

Game::~Game()
{
    delete images;
    images = NULL;
    destroy_bitmap(buffer);
    current = NULL;

    std::vector<Level*>::iterator itr = levels.begin();
    for(; itr != levels.end(); itr++)
        delete *itr;
    levels.clear();

    std::vector<Map*>::iterator itr2 = maps.begin();
    for(; itr2 != maps.end(); itr2++)
        delete *itr2;
    maps.clear();
}
