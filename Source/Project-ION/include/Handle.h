#ifndef HANDLE_H
#define HANDLE_H
#include "Structure.h"

class Handle: public Structure
{
public:
    Handle();
    Handle(float x, float y, List_Images* img);
    void switch_on();
    static int getSwitchedOn();
    virtual ~Handle();
private:
    List_Images* img;
    bool on;
    static int switched_on;
};

#endif // HANDLE_H
