#include "Level_3.h"

Level_3::Level_3()
{

}

Level_3::Level_3(BITMAP* buffer, Images* images, Human* jack):Level(buffer, images, jack)
{
   int** m = new int*[24];
    for(int i = 0; i<24; i++)
        m[i] = new int[36];

    int m1[24][36]
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 2, 2, 2, 2, 2, 3, 3, 3, 2, 2, 3, 3, 3, 2, 2, 0, 2, 2, 2, 2, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 0, 0},
        {0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0},
        {0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0},
        {0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
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

int Level_3::gameLoop()
{
    game_status = genericGameLoop();

    if(iterations % 4 == 0){
        fireballs->print(buffer);
    }

    if(iterations % 7 == 0){
        lavas->createFireballs(fireballs);
    }

    if(iterations == 3){
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

    if(jack->getx() <= -20){
        resetPlayer(1050,jack->gety());
        return 3; //prev level
    }
    else if(jack->getx() >= 1075){
        resetPlayer(-15,jack->gety());
        return 2; //next level
    }

}

void Level_3::generateLevel(List_Characters* characters){
    this->characters = characters;
    was_genereted = 1;
}

void Level_3::generateLevel(){

    if(!was_genereted){
        resetLevel();
        if(rand()%2 == 0)
        {
            Topspin* top1 = new Topspin(590, 400, images->getImgsTopspin(),-1);
            characters->include(static_cast<Character*>(top1));
        }

        if(rand()%2 == 0)
        {
            Topspin* top2 = new Topspin(590, 400, images->getImgsTopspin(),1);
            characters->include(static_cast<Character*>(top2));
        }

        if(rand()%2 == 0)
        {
            Topspin* top3 = new Topspin(500, 400, images->getImgsTopspin(),-1);
            characters->include(static_cast<Character*>(top3));
        }

        if(rand()%2 == 0)
        {
            Topspin* top4 = new Topspin(500, 400, images->getImgsTopspin(),1);
            characters->include(static_cast<Character*>(top4));
        }

        if(rand()%2 == 0)
        {
            Topspin* top5 = new Topspin(540, 400, images->getImgsTopspin(),-1);
            characters->include(static_cast<Character*>(top5));
        }

        if(rand()%2 == 0)
        {
            Bat* batman1 = new Bat(150,120,images->getImgsBat(),1,1,650,150);
            characters->include(static_cast<Character*>(batman1));
        }

        if(rand()%2 == 0)
        {
            Bat* batman2 = new Bat(800,120,images->getImgsBat(),-1,1,650,150);
            characters->include(static_cast<Character*>(batman2));
        }

        if(rand()%2 == 0)
        {
            Bat* batman3 = new Bat(60,330,images->getImgsBat(),1,1,810,0);
            characters->include(static_cast<Character*>(batman3));
        }

        if(rand()%2 == 0)
        {
            Bat* batman4 = new Bat(240,520,images->getImgsBat(),1,1,240,30);
            characters->include(static_cast<Character*>(batman4));
        }

        if(rand()%2 == 0)
        {
            Bat* batman5 = new Bat(960,390,images->getImgsBat(),-1,1,280,120);
            characters->include(static_cast<Character*>(batman5));
        }

        was_genereted = 1;
    }
}

void Level_3::eraseAll(){
    characters->eraseAll();
    fireballs->eraseAll();
    was_genereted = 0;
}

void Level_3::resetLevel(){}

Level_3::~Level_3()
{
    //dtor
}
