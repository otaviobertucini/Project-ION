#include "Main.h"

Main::Main()
{
    allegro_init();
    install_keyboard();
    install_mouse();
    show_mouse(screen);
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1080, 720, 0, 0);
    buffer = create_bitmap(1080, 720);
    menu = new Menu(buffer);
    exit = false;
}

void Main::execute(){
    while(!exit){
        int start = menu->inicial();
        if(start == 1){
            solo = new SoloGame(menu, buffer);
            solo->execute();
        }
        if(start == 0){
            exit = true;
        }
    }
}

Main::~Main()
{
    delete solo;
    solo = NULL;
    delete menu;
    menu = NULL;
    destroy_bitmap(buffer);
}
