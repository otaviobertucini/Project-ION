#ifndef BIRL_H
#define BIRL_H

#include <Powerup.h>


class Birl : public Powerup
{
public:
    Birl();
    Birl(float x, float y);
    void modify(Human* a);
    virtual ~Birl();
private:
};

#endif // BIRL_H
