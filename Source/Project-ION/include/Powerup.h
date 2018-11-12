#ifndef POWERUP_H
#define POWERUP_H
#include <string>
#include "Entity.h"
#include "Human.h"

class Powerup : public Entity
{
public:
    Powerup();
    Powerup(float x, float y, BITMAP* current_img);
    void setPosMatrix();
    void loop();
    virtual void modify(Human* a) = 0;
    virtual ~Powerup();
protected:
    std::string type;
};

#endif // POWERUP_H
