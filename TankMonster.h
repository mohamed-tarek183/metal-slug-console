#ifndef TANKMONSTER_H_INCLUDED
#define TANKMONSTER_H_INCLUDED
#include "Monster.h"

class TankMonster : public Monster {
private:
    int shield;

public:
    TankMonster(char t, int x, int y, int hp, int s);

    int getShield() const;
    void setShield(int s);
};


#endif // TANKMONSTER_H_INCLUDED
