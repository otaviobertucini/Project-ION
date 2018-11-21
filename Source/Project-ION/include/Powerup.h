#ifndef POWERUP_H
#define POWERUP_H
#include <string>
#include "Entity.h"
#include "Human.h"

class Powerup : public Entity
{
public:
    Powerup();
    Powerup(float x, float y);
    virtual void modify(Human* a) = 0;
    void saveLevel(std::ofstream& myfile);
    virtual ~Powerup();
protected:
    std::string type;
};

#endif // POWERUP_H
