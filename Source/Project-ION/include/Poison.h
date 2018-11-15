#ifndef POISON_H
#define POISON_H
#include "Moveable.h"
#include <fstream>

class Poison: public Moveable
{
public:
    Poison();
    Poison(float x, float y, BITMAP* current_img, int direction);
    void loop();
    void move(int x_move);
    const bool getMoveSide() const;
    void saveState(std::ofstream& file) const;
    virtual ~Poison();
private:
};

#endif // POISON_H
