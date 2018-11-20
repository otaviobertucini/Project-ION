#include "Boss.h"

Boss::Boss(): speed(0.25)
{
    //ctor
}

Boss::Boss(float x, float y, Human* jack):Enemy(x, y), speed(0.25){
    h = 70;
    w = 70;
    this->jack = jack;
    timer = 2001;
    last_poison = 0;
    List_Images* img = Images::imgsBoss;
    current_img = (*img)[0];
}

void Boss::move(int x_move){
    int y_move;

    if(jack->gety() > 120 )
    {
        if(jack->gety() < y)
            y_move = -1;
        else if(jack->gety() == y)
            y_move = 0;
        else
            y_move = 1;
    }
    else
        y_move = 0;

    if(y_move == -1)
        y -= speed;
    else if(y_move == 1)
        y += speed;
}

void Boss::loop(){
    if(last_poison != 0){
        timer = (clock() - last_poison)/double(CLOCKS_PER_SEC)*1000;
    }
    verifyDirection();
    move(0);
}

void Boss::createPoison(List_Poisons* poisons){
    if(abs(jack->gety() - y) <= 10 && timer > 2000){
        last_poison = clock();
        timer = 0;
        BITMAP* img = load_bitmap("Material/Enemy/poison.bmp", NULL);
        Poison* p = new Poison(side_ball, y + h/2, img, direction);
        poisons->include(p);
    }
}

void Boss::verifyDirection(){
    List_Images* img = Images::imgsBoss;
    if(jack->getx() > x + w/2){
        direction = -1;
        side_ball = x+w;
        current_img = (*img)[2];
    }
    else{
        direction = 1;
        side_ball = x;
        current_img = (*img)[0];
    }
}

void Boss::saveState(std::ofstream& myfile) const{
    myfile << "BOS:" << x << "," << y << "\n";
}

Boss::~Boss()
{
    //dtor
}
