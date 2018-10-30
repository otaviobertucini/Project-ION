#include "SoloGame.h"

SoloGame::SoloGame():Game()
{
    images = new Images;
    buffer = create_bitmap(1080, 720);

    //Level 0
    level0();
}

void SoloGame::execute()
{
    while(!key[KEY_ESC])
    {
        current->gameLoop();
        draw_sprite(screen, buffer, 0, 0);
        clear_bitmap(buffer);
    }
}

void SoloGame::level0(){
    Tutorial* tutorial = new Tutorial(buffer, images);
    current = static_cast<Level*>(tutorial);
}

SoloGame::~SoloGame()
{
}
