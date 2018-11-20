#include "Lava.h"

Lava::Lava()
{
    //ctor
}

Lava::Lava(float x, float y, int id):Obstacle(x, y){
    w = 30;
    h = 30;
    List_Images* img = Images::imgsMap;
    current_img = (*img)[17+id];
}

Fireball* Lava::createFireball(){
    int num = rand()%3000;
    if(num == 0){
        int rand_size = rand()%30;
        Fireball* fire = new Fireball(x+rand_size, y);
        return fire;
    }
    return NULL;
}

Lava::~Lava()
{
    //dtor
}
