#ifndef STRUCTURE_H
#define STRUCTURE_H
#include <math.h>
#include "Entity.h"

class Structure: public Entity
{
public:
    Structure();
    Structure(float x, float y, BITMAP* current_img);
    void setPosMatrix();
    void print(BITMAP* screen);
    virtual void loop() = 0;
    virtual ~Structure();
protected:

};

#endif // STRUCTURE_H
