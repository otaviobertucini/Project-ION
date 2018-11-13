#include "Lava.h"

Lava::Lava()
{
    //ctor
}

Lava::Lava(float x, float y, BITMAP* current_img):Obstacle(x, y, current_img){
    w = 30;
    h = 30;
}

void Lava::setPosMatrix(){}

void Lava::loop(){}

Fireball* Lava::createFireball(){
    int num = rand()%500;
    if(num == 69){
        int rand_size = rand()%30;
        BITMAP* img = load_bitmap("Material/Enemy/fireball.bmp", NULL);
        Fireball* fire = new Fireball(x+rand_size, y, img);
        return fire;
    }
    return NULL;
}

Lava::~Lava()
{
    //dtor
}
