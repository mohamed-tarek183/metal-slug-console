#ifndef AMMO_H_INCLUDED
#define AMMO_H_INCLUDED
#include "Item.h"

class Ammo : public Item {
private:
    int bullets;

public:
    Ammo(int b);

    int getBullets() ;
};


#endif // AMMO_H_INCLUDED
