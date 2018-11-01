#include "Menu.h"

Menu::Menu()
{
    //ctor
}

Menu::Menu(BITMAP* buffer){
    this->buffer = buffer;
    img_back = load_bitmap("Material/back.bmp", NULL);
    cursor = load_bitmap("Material/Scenario/pack_1.bmp", NULL);
    pause_back = load_bitmap("Material/pause.bmp", NULL);
}

int Menu::inicial(){
    bool exit = false;
    int option = 1;
    float y_cursor;
    //show_mouse(screen);
    while(!exit){
        draw_sprite(buffer, img_back, 0, 0);
        if(key[KEY_ESC]){
            exit = true;
        }
        if(key[KEY_ENTER]){
            if(option == 1)
                return 1;
            if(option == 2)
                return 0;
        }

        if(key[KEY_UP]){
            rest(100);
            if(option == 1)
                option = 2;
            else
                option = 1;
        }

        if(option == 1){
            y_cursor = 325;
        }
        else if(option == 2){
            y_cursor = 455;
        }

        draw_sprite(buffer, cursor, 225, y_cursor);
        blit(buffer, screen, 0, 0, 0, 0, 1080, 720);
        clear(buffer);
    }
}

int Menu::pause(){
    bool exit = false;
    int option = 1;
    float y_cursor;
    //show_mouse(screen);
    while(!exit){
        draw_sprite(buffer, pause_back, 0, 0);
        if(key[KEY_ESC]){
            return 1;
        }
        if(key[KEY_ENTER]){
            if(option == 1)
                return 1;
            if(option == 2)
                return 0;
        }

        if(key[KEY_UP]){
            rest(100);
            if(option == 1)
                option = 2;
            else
                option = 1;
        }

        if(option == 1){
            y_cursor = 300;
        }
        else if(option == 2){
            y_cursor = 414;
        }

        draw_sprite(buffer, cursor, 225, y_cursor);
        blit(buffer, screen, 0, 0, 0, 0, 1080, 720);
        clear(buffer);
    }
}

Menu::~Menu()
{
    //dtor
}
