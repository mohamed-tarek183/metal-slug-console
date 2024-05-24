#ifndef RIFLE_H_INCLUDED
#define RIFLE_H_INCLUDED
#include "Gun.h"

class Rifle : public Gun {
public:
    Rifle();
     void useSpecial(Hero& h1 , Object* grid[15][15]);
};


#endif // RIFLE_H_INCLUDED
