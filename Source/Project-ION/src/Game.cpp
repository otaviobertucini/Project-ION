#include "Game.h"

Game::Game()
{
    allegro_init();
    install_keyboard();
    install_mouse();
    show_mouse(screen);
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1080, 720, 0, 0);
    buffer = create_bitmap(1080, 720);
}

Game::~Game()
{
    delete images;
    images = NULL;
    destroy_bitmap(buffer);
    current = NULL;

    //delete levels; //giving segmentation error
}
