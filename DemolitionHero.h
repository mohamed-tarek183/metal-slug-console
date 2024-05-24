#ifndef DEMOLITIONHERO_H_INCLUDED
#define DEMOLITIONHERO_H_INCLUDED
#include "Hero.h"

class DemolitionHero : public Hero {
private:
    Gun* weapon2;

public:
    DemolitionHero(char t, int x, int y, int hp);
    void setWeapon2(Gun *g);
    Gun* getWeapon2();
    friend ostream& operator<<(ostream& os,  DemolitionHero& h);
    friend Hero& operator+( DemolitionHero& h, Ammo& a) ;
    void useSpecial();
};


#endif // DEMOLITIONHERO_H_INCLUDED
