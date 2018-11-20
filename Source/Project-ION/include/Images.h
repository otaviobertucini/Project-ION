#ifndef Images_Library_H
#define Images_Library_H
#include <allegro.h>
//#include <winalleg.h>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <cstddef> //library for NULL
#include "List_Images.h"
using std::cout;
using std::endl;

class Images_Library
{
public:
    Images_Library();
    ~Images_Library();
    static List_Images* imgsJack;
    static List_Images *imgsMap;
    static List_Images *imgsTopspin;
    static List_Images *imgsFireball;
    static List_Images *imgsBat;
    static List_Images *imgsBoss;
    static List_Images *imgsHandle;
};

#endif // Images_Library_H
