#ifndef ENTITY_H
#define ENTITY_H
#include <allegro.h>
#include <vector>

class Entity
{
public:
    Entity();
    Entity(float x, float y, std::vector<BITMAP*> *img);
    virtual void setPosMatrix() = 0;
    void getPosMatrix(int* i, int* j);
    virtual void print(BITMAP* screen) = 0;
    virtual ~Entity();
protected:
    float x;
    float y;
    std::vector<BITMAP*> *img;
    int i_pos;
    int j_pos;
};

#endif // ENTITY_H
