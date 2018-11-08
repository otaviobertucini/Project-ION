#include "Images.h"

Images::Images()
{
    //Loads images from Jack
    imgsJack = new List_Images;
    imgsJack->include(load_bitmap("Material/Scenario/jack_1.bmp", NULL));

    //Loads images from map
    imgsMap = new List_Images;
    imgsMap->include(load_bitmap("Material/Scenario/stone_1.bmp", NULL));
    imgsMap->include(load_bitmap("Material/Scenario/lava_1.bmp", NULL));
    imgsMap->include(load_bitmap("Material/Scenario/lava_2.bmp", NULL));
    imgsMap->include(load_bitmap("Material/Scenario/spine_1.bmp", NULL));
    imgsMap->include(load_bitmap("Material/Scenario/spine_2.bmp", NULL));
    imgsMap->include(load_bitmap("Material/Scenario/spine_3.bmp", NULL)); //5
    imgsMap->include(load_bitmap("Material/Scenario/spine_4.bmp", NULL));
    imgsMap->include(load_bitmap("Material/Powerups/birl.bmp", NULL));

    //Loads images from topspin
    imgsTopspin = new List_Images;
    imgsTopspin->include(load_bitmap("Material/Enemy/topSpin_Walk_1.bmp", NULL));
    imgsTopspin->include(load_bitmap("Material/Enemy/topSpin_Walk_2.bmp", NULL));

    //Loads images from fireball
    imgsFireball = new List_Images;
    imgsFireball->include(load_bitmap("Material/Enemy/fireball.bmp", NULL));

    //loads images from bat
    imgsBat = new List_Images;
    imgsBat->include(load_bitmap("Material/Enemy/bat_test.bmp", NULL));
}

List_Images* Images::getImgsJack(){
    return imgsJack;
}

List_Images* Images::getImgsMap(){
    return imgsMap;
}

List_Images* Images::getImgsTopspin(){
    return imgsTopspin;
}

List_Images* Images::getImgsFireball(){
    return imgsFireball;
}

List_Images* Images::getImgsBat(){
    return imgsBat;
}

Images::~Images()
{
    imgsJack->deleteAll();
    imgsMap->deleteAll();
    imgsTopspin->deleteAll();
}
