#include "Images.h"

Images_Library::Images_Library()
{
    //Loads Images_Library from Jack
    imgsJack = new List_Images;
    imgsJack->include(load_bitmap("Material/Scenario/jack_1.bmp", NULL));
    imgsJack->include(load_bitmap("Material/Scenario/jack_2.bmp", NULL));
    imgsJack->include(load_bitmap("Material/Scenario/jack_3.bmp", NULL));
    imgsJack->include(load_bitmap("Material/Scenario/jack_4.bmp", NULL));

    //Loads Images_Library from map
    imgsMap = new List_Images;
    imgsMap->include(load_bitmap("Material/Scenario/stone_1.bmp", NULL));
    imgsMap->include(load_bitmap("Material/Scenario/stone_2.bmp", NULL));
    imgsMap->include(load_bitmap("Material/Scenario/stone_3.bmp", NULL));
    imgsMap->include(load_bitmap("Material/Scenario/stone_4.bmp", NULL));
    imgsMap->include(load_bitmap("Material/Scenario/stone_5.bmp", NULL));
    imgsMap->include(load_bitmap("Material/Scenario/stone_6.bmp", NULL)); //5
    imgsMap->include(load_bitmap("Material/Scenario/stone_7.bmp", NULL));
    imgsMap->include(load_bitmap("Material/Scenario/stone_8.bmp", NULL));
    imgsMap->include(load_bitmap("Material/Scenario/stone_9.bmp", NULL));
    imgsMap->include(load_bitmap("Material/Scenario/stone_10.bmp", NULL));
    imgsMap->include(load_bitmap("Material/Scenario/stone_11.bmp", NULL));//10
    imgsMap->include(load_bitmap("Material/Scenario/stone_12.bmp", NULL));
    imgsMap->include(load_bitmap("Material/Scenario/stone_13.bmp", NULL));
    imgsMap->include(load_bitmap("Material/Scenario/stone_14.bmp", NULL));
    imgsMap->include(load_bitmap("Material/Scenario/stone_15.bmp", NULL));
    imgsMap->include(load_bitmap("Material/Scenario/stone_16.bmp", NULL));//15
    imgsMap->include(load_bitmap("Material/Scenario/stone_17.bmp", NULL));
    imgsMap->include(load_bitmap("Material/Scenario/lava_1.bmp", NULL));
    imgsMap->include(load_bitmap("Material/Scenario/lava_2.bmp", NULL));
    imgsMap->include(load_bitmap("Material/Scenario/spine_1.bmp", NULL));
    imgsMap->include(load_bitmap("Material/Scenario/spine_2.bmp", NULL));//20
    imgsMap->include(load_bitmap("Material/Scenario/spine_3.bmp", NULL));
    imgsMap->include(load_bitmap("Material/Scenario/spine_4.bmp", NULL));
    imgsMap->include(load_bitmap("Material/Powerups/birl.bmp", NULL));
    imgsMap->include(load_bitmap("Material/Enemy/fireball.bmp", NULL));


    //loads Images_Library from handle
    imgsHandle = new List_Images;
    imgsHandle->include(load_bitmap("Material/Scenario/lever_switch_1.bmp", NULL));
    imgsHandle->include(load_bitmap("Material/Scenario/lever_switch_2.bmp", NULL));

    //Loads Images_Library from topspin
    imgsTopspin = new List_Images;
    imgsTopspin->include(load_bitmap("Material/Enemy/topSpin_Walk_1.bmp", NULL));
    imgsTopspin->include(load_bitmap("Material/Enemy/topSpin_Walk_2.bmp", NULL));

    //Loads Images_Library from fireball
    imgsFireball = new List_Images;
    imgsFireball->include(load_bitmap("Material/Enemy/fireball.bmp", NULL));

    //loads Images_Library from bat
    imgsBat = new List_Images;
    imgsBat->include(load_bitmap("Material/Enemy/bat_1.bmp", NULL));
    imgsBat->include(load_bitmap("Material/Enemy/bat_2.bmp", NULL));

    //loads Images_Library from boss
    imgsBoss = new List_Images;
    imgsBoss->include(load_bitmap("Material/Enemy/boss_1.bmp", NULL));
    imgsBoss->include(load_bitmap("Material/Enemy/boss_2.bmp", NULL));
    imgsBoss->include(load_bitmap("Material/Enemy/boss_3.bmp", NULL));
    imgsBoss->include(load_bitmap("Material/Enemy/boss_4.bmp", NULL));
}

List_Images* Images_Library::imgsJack = NULL;
List_Images* Images_Library::imgsBat = NULL;
List_Images* Images_Library::imgsMap = NULL;
List_Images* Images_Library::imgsTopspin = NULL;
List_Images* Images_Library::imgsFireball = NULL;
List_Images* Images_Library::imgsBoss = NULL;
List_Images* Images_Library::imgsHandle = NULL;

Images_Library::~Images_Library()
{
    imgsJack->deleteAll();
    imgsMap->deleteAll();
    imgsTopspin->deleteAll();
    imgsFireball->deleteAll();
    imgsBat->deleteAll();
    imgsBoss->deleteAll();
}
