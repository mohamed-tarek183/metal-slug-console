#ifndef BAZOOKA_H_INCLUDED
#define BAZOOKA_H_INCLUDED
#include "Gun.h"
class Bazooka : public Gun {
public:
    Bazooka();
    void useSpecial(Hero& h1 , Object* grid [15][15]);
};



#endif // BAZOOKA_H_INCLUDED
