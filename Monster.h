#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED
#include "Character.h"

class Monster : public Character {
public:
    Monster(char t, int x, int y, int hp);
};


#endif // MONSTER_H_INCLUDED
