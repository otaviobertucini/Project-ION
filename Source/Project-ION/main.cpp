#include <allegro.h>
#include <stdlib.h>
#include <time.h>
#include <cstddef> //library for NULL
#include <iostream>
#include "Level.h"
#include "SoloGame.h"
using std::cout;
using std::endl;

int main() {

    SoloGame game;
    game.execute();
    return 0;
}
END_OF_MAIN();
