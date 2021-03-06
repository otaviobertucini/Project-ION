#ifndef FIREBALL_H
#define FIREBALL_H
#include "List_Images.h"
#include "Enemy.h"
#include "Moveable.h"

class Fireball : public Mover
{
public:
    Fireball();
    Fireball(float x, float y);
    void move(int x_move);
    void saveState(std::ofstream& myfile) const;
    void loop();
    const bool getMoveUp() const;
    virtual ~Fireball();
private:
};

#endif // FIREBALL_H
