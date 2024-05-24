#ifndef MEDICHERO_H_INCLUDED
#define MEDICHERO_H_INCLUDED
#include "Hero.h"

class MedicHero : public Hero {
private:
    int healingAmount;

public:
    MedicHero(char t, int x, int y, int hp, int ha);

    int getHealingAmount();
    void useSpecial();
    friend ostream& operator<<(ostream& os,  MedicHero& h);
};


#endif // MEDICHERO_H_INCLUDED
