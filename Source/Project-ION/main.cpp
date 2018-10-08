#include <allegro.h>
#include <stdlib.h>
#include <time.h>
#include <cstddef> //library for NULL
#include <iostream>
using std::cout;
using std::endl;

int main() {
    allegro_init();
    install_keyboard();
    set_color_depth(32);
    srand(time(NULL));
    int res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1080, 720, 0, 0);
    if(res == 0)
        cout << "GFX OK" << endl;

    BITMAP *stone_1 = load_bitmap("/home/otavio/Documentos/Project_ION/Material/Scenario/stone_1.bmp", NULL);
    BITMAP *stone_2 = load_bitmap("/home/otavio/Documentos/Project_ION/Material/Scenario/stone_2.bmp", NULL);
    BITMAP *stone_3 = load_bitmap("/home/otavio/Documentos/Project_ION/Material/Scenario/stone_3.bmp", NULL);
    if(stone_3 == NULL){
        cout << "merda convertendo" << endl;
    }
    int rando;
    for(int i = 0; i < 36; i++){
        for(int j = 0; j < 24; j++){
            rando = rand()%3;
            //cout << rando << endl;
            if(rando == 0)
                blit(stone_1, screen, 0, 0, 30*i, 30*j, 30, 30);
            else if(rando == 1)
                blit(stone_2, screen, 0, 0, 30*i, 30*j, 30, 30);
            else if(rando == 2)
                blit(stone_3, screen, 0, 0, 30*i, 30*j, 30, 30);
        }
    }
    while(!key[KEY_ESC]){
        continue;
    }
    return 0;
}
END_OF_MAIN();
