#ifndef STRUCTURE_H
#define STRUCTURE_H
#include <math.h>
#include "Entity.h"

class Structure: public Entity
{
public:
    Structure();
    Structure(float x, float y);
    void setPosMatrix();
    virtual ~Structure();
protected:

};

#endif // STRUCTURE_H
