#include "Lava.h"

Lava::Lava()
{
    //ctor
}

Lava::Lava(float x, float y, List_Images* img, int id):Obstacle(x, y, (*img)[18]){
    w = 30;
    h = 30;
    this->img = img;
    current_img = (*img)[17+id];
}

Fireball* Lava::createFireball(){

    int num = rand()%3000;

    if(num == 0){
        int rand_size = rand()%30;
        //BITMAP* img = load_bitmap("Material/Enemy/fireball.bmp", NULL);
        Fireball* fire = new Fireball(x+rand_size, y, (*img)[24]);
        return fire;
    }
    return NULL;
}

Lava::~Lava()
{
    //dtor
}
