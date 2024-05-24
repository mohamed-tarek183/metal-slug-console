#ifndef GHOSTMONSTER_H_INCLUDED
#define GHOSTMONSTER_H_INCLUDED
#include "Monster.h"

class GhostMonster : public Monster {
private:
    bool isVisible;

public:
    GhostMonster(char t, int x, int y, int hp);

    bool isVisibleOnMap() ;
    void setVisibility(bool v);
};


#endif // GHOSTMONSTER_H_INCLUDED
