#ifndef PISTOL_H_INCLUDED
#define PISTOL_H_INCLUDED
#include "Gun.h"
class Game;
class Pistol : public Gun {
public:
    Pistol();
     void useSpecial(Hero& h1 , Object* grid [15][15]);
};





#endif // PISTOL_H_INCLUDED
