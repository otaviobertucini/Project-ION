#include "Level_1.h"

Level_1::Level_1()
{
    //ctor


}

Level_1::Level_1(BITMAP* buffer, Images* images, Human* jack):Level(buffer, images, jack){

    int** m = new int*[24];
    for(int i = 0; i<24; i++)
        m[i] = new int[36];

    int m1[24][36]
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0}
    };

    for(int i = 0; i<24; i++)
    {
        for(int j = 0; j<36; j++)
        {
            m[i][j] = m1[i][j];
        }
    }

    fireballs = new List_Fireballs;
    generateMap(m);
}

int Level_1::gameLoop(){

    game_status = genericGameLoop();

    if(iterations % 4 == 0){
        fireballs->print(buffer);
    }

    if(iterations % 7 == 0){
        lavas->createFireballs(fireballs);
    }

    if(iterations % 5 == 0){
        structures->isCollide(fireballs);
        fireballs->loop();
    }

    if(iterations == 5){
        if(fireballs->isCollide(jack)){
            return 0;
        }
    }

    if(game_status != 1)
        return game_status;

    if(jack->getx() >= 1075 && jack->gety() >= 0){
        resetPlayer(-15,jack->gety());
        return 2; //next level
    }
    else if(jack->getx() <= -20){
        resetPlayer(1050,jack->gety());
        return 3; //prev level
    }

    return 1;
}

void Level_1::generateLevel(){

    resetLevel();

    if(!was_genereted)
    {
        if(rand()%2 == 0)
        {
            Topspin* top = new Topspin(330, 190, images->getImgsTopspin());
            characters->include(static_cast<Character*>(top));
        }

        if(rand()%2 == 0)
        {
            Topspin* top2 = new Topspin(440, 190, images->getImgsTopspin(),-1);
            characters->include(static_cast<Character*>(top2));
        }

        if(rand()%2 == 0)
        {
            Topspin* top3 = new Topspin(940, 530, images->getImgsTopspin(),-1);
            characters->include(static_cast<Character*>(top3));
        }

        if(rand()%2 == 0)
        {
            Topspin* top4 = new Topspin(910, 530, images->getImgsTopspin());
            characters->include(static_cast<Character*>(top4));
        }

        if(rand()%2 == 0)
        {
            Topspin* top5 = new Topspin(540, 530, images->getImgsTopspin());
            characters->include(static_cast<Character*>(top5));
        }

        if(rand()%2 == 0)
        {
            Bat* batman1 = new Bat(210,240,images->getImgsBat(),1,1,270,80);
            characters->include(static_cast<Character*>(batman1));
        }

        if(rand()%2 == 0)
        {
            Bat* batman2 = new Bat(480,240,images->getImgsBat(),-1,1,270,80);
            characters->include(static_cast<Character*>(batman2));
        }

        if(rand()%2 == 0)
        {
            Bat* batman3 = new Bat(390,60,images->getImgsBat(),1,1,390,40);
            characters->include(static_cast<Character*>(batman3));
        }

        if(rand()%2 == 0)
        {
            Bat* batman4 = new Bat(780,60,images->getImgsBat(),-1,1,390,40);
            characters->include(static_cast<Character*>(batman4));
        }

        if(rand()%2 == 0)
        {
            Bat* batman5 = new Bat(810,60,images->getImgsBat(),1,1,60,390);
            characters->include(static_cast<Character*>(batman5));
        }

        was_genereted = 1;
    }
}

void Level_1::generateLevel(List_Characters* characters){
}

void Level_1::resetLevel(){}

Level_1::~Level_1()
{
    //dtor
}
