#ifndef STONE_H
#define STONE_H
#include "Structure.h"

class Stone: public Structure
{
public:
    Stone();
    Stone(float x, float y, int side);
    virtual ~Stone();
private:
};

#endif // STONE_H
