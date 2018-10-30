#ifndef STONE_H
#define STONE_H
#include "Structure.h"

class Stone: public Structure
{
public:
    Stone();
    Stone(float x, float y, BITMAP* current_img);
    void loop();
    virtual ~Stone();
private:
};

#endif // STONE_H
