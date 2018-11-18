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
    login_back = load_bitmap("Material/login_back.bmp",NULL);
    rank_back = load_bitmap("Material/rank_back.bmp",NULL);
    font_main = load_font("Fonts/ImpactFont.pcx", NULL, NULL);
}

int Menu::inicial(){
    //cout << "aqui" << endl;
    bool exit = false;
    bool confirmButton = false;
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

        if(key[KEY_ENTER] && confirmButton)
        {
            if(option == 1){
                return 1;
            }
            if(option == 3)
            {
                ranking();
                confirmButton = false;
            }
            if(option == 4){
                return 0;
            }
        }
        if(!key[KEY_ENTER])
            confirmButton = true;

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

        if(key[KEY_ENTER]){
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
            y_cursor = 260;
        }
        else if(option == 2){
            y_cursor = 414;
        }

        draw_sprite(buffer, cursor, 330, y_cursor);
        blit(buffer, screen, 0, 0, 0, 0, 1080, 720);
        clear(buffer);
    }
    return 0;
}

int Menu::sologame(){
    bool exit = false;
    bool confirmButton = false;
    int option = 1;
    float y_cursor;
    //show_mouse(screen);
    while(!exit){
        draw_sprite(buffer, solo_back, 0, 0);
        if(key[KEY_E]){
            return 1;
        }
        if(key[KEY_R]){
            return 2;
        }

        if(key[KEY_ENTER] && confirmButton){
            if(option == 1)
                return 1;
            if(option == 2)
                return 2;
        }
        if(!key[KEY_ENTER])
            confirmButton = true;

        if(key[KEY_UP]){
            rest(200);
            option = 1;
        }

        if(key[KEY_DOWN]){
            rest(200);
            option = 2;
        }

        if(option == 1){
            y_cursor = 260;
        }
        else if(option == 2){
            y_cursor = 414;
        }

        draw_sprite(buffer, cursor, 310, y_cursor);
        blit(buffer, screen, 0, 0, 0, 0, 1080, 720);
        clear(buffer);
    }
    return 0;
}

void Menu::ranking()
{
    bool exit = false;
    bool confirm = false;
    List_user listAux;
    User *userAux;
    int size;
    listAux.Import_List();
    size = listAux.getSize();

    while(!exit){
        draw_sprite(buffer, rank_back, 0, 0);

        for(int i = 0; i < size && i < 10; i++)
        {
            userAux = listAux.getUser(i);

            textout_ex(buffer, font_main, userAux->getName().c_str() , 150, 150 + (i * 50), makecol(255, 255, 255),-1);

            std::stringstream forTextout;
            forTextout << userAux->getLevel();

            textout_ex(buffer, font_main, forTextout.str().c_str() , 520, 150 + (i * 50), makecol(255, 255, 255),-1);

            forTextout.str("");
            forTextout << userAux->getScore();

            textout_ex(buffer, font_main, forTextout.str().c_str(), 800, 150 + (i * 50), makecol(255, 255, 255),-1);
        }

        if(key[KEY_ENTER] && confirm)
            exit = true;
        if(!key[KEY_ENTER])
            confirm = true;

        blit(buffer, screen, 0, 0, 0, 0, 1080, 720);
        clear(buffer);
    }
}


string Menu::readMenu()
{
    string editText;
    string::iterator iter;
    int caret;
    bool insert;
    bool confirm;
    bool confirmEnter;

    iter = editText.begin();
    caret = 0;
    insert = true;
    confirm = true;
    confirmEnter=false;

    while(confirm)
    {
        while(keypressed())
        {
            int newkey = readkey();
            char ASCII = newkey & 0xff;

            if(ASCII >= 32 && ASCII <= 126 && caret <= 15)
            {
                if(insert || iter == editText.end())
                    iter = editText.insert(iter, ASCII);
                else
                    editText.replace(caret, 1, 1, ASCII);
                caret++;
                iter++;
            }

            if(key[KEY_ENTER] && confirmEnter && caret != 0)
                    confirm = false;
            if(key[KEY_BACKSPACE])
            {
                if(iter != editText.begin())
                {
                    caret--;
                    iter--;
                    iter = editText.erase(iter);
                }
            }
            if(!key[KEY_ENTER])
                confirmEnter = true;

            clear(buffer);
            draw_sprite(buffer, login_back, 0, 0);
            textout_ex(buffer, font_main, editText.c_str() , 400, 340, makecol(255, 255, 255),-1);
            blit(buffer, screen, 0, 0, 0, 0, 1080, 720);
        }
    }
    string teste = editText;
    return teste;
}

Menu::~Menu()
{
    destroy_bitmap(img_back);
    destroy_bitmap(cursor);
    destroy_bitmap(pause_back);
    destroy_bitmap(solo_back);
    destroy_bitmap(login_back);
    destroy_font(font_main);
}
