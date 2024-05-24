#ifndef POTION_H_INCLUDED
#define POTION_H_INCLUDED
#include "Item.h"

class Potion : public Item {
private:
    int healingAmount;

public:
    Potion(int ha);

    int getHealingAmount() const;
};


#endif // POTION_H_INCLUDED
