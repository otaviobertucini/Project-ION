#ifndef HANDLE_H
#define HANDLE_H
#include "Structure.h"
#include <fstream>

class Handle: public Structure
{
public:
    Handle();
    Handle(float x, float y, List_Images* img, bool on = 0);
    void switch_on();
    static int getSwitchedOn();
    static void setSwitchedOn(const int n);
    void saveState(std::ofstream& myfile) const;
    virtual ~Handle();
private:
    List_Images* img;
    bool on;
    static int switched_on;
};

#endif // HANDLE_H
