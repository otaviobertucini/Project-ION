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
    solo_back = load_bitmap("Material/solo_back.bmp", NULL);
}

int Menu::inicial(){
    //cout << "aqui" << endl;
    bool exit = false;
    int option = 1;
    float y_cursor;
    //show_mouse(screen);
    while(!exit){
        draw_sprite(buffer, img_back, 0, 0);
        if(key[KEY_E]){
            exit = true;
        }
        if(key[KEY_T]){
            return 2;
        }
        if(key[KEY_ENTER]){
            if(option == 1){
                return 1;
            }
            if(option == 4){
                return 0;
            }
        }

        if(key[KEY_UP] && option > 1){
            rest(200);
            option -= 1;
        }
        if(key[KEY_DOWN] && option < 4){
            rest(200);
            option += 1;
        }

        if(option == 1)
            y_cursor = 125;
        else if(option == 2)
            y_cursor = 235;
        else if(option == 3)
            y_cursor = 335;
        else if(option == 4)
            y_cursor = 435;

        draw_sprite(buffer, cursor, 700, y_cursor);
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
        if(key[KEY_E]){
            return 1;
        }
        if(key[KEY_R]){
            return 2;
        }

        if(key[KEY_SPACE]){
            if(option == 1)
                return 1;
            if(option == 2)
                return 0;
        }

        if(key[KEY_UP]){
            rest(200);
            option = 1;
        }

        if(key[KEY_DOWN]){
            rest(200);
            option = 2;
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
    return 0;
}

int Menu::sologame(){
    bool exit = false;
    while(!exit){
        draw_sprite(buffer, solo_back, 0, 0);
        if(key[KEY_J]){
            return 1;
        }
        if(key[KEY_T]){
            return 2;
        }

        if(key[KEY_ESC]){
            exit = true;
        }

        blit(buffer, screen, 0, 0, 0, 0, 1080, 720);
        clear(buffer);
    }
    return 0;
}

Menu::~Menu()
{
    destroy_bitmap(img_back);
    destroy_bitmap(cursor);
    destroy_bitmap(pause_back);
    destroy_bitmap(solo_back);
}
