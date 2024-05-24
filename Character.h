#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED
#include "Object.h"
 class Character : public Object {
protected:
    int positionX;
    int positionY;
    int healthPoints;

public:
    Character(char t, int x, int y, int hp);

    int getPositionX();
    int getPositionY();
    int getHealthPoints();

    void setPosition(int x, int y);
    void setHealthPoints(int hp);

};
#endif // CHARACTER_H_INCLUDED
