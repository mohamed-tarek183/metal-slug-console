#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED
#include "Character.h"

#include"Ammo.h"
#include"Potion.h"
#include"Monster.h"
class Gun;
class Hero : public Character {
private:
    Gun* weapon;

public:
    Hero(char t, int x, int y, int hp);

    Gun* getWeapon();
    void setWeapon(Gun* g);
  friend ostream& operator<<(ostream& os, const Hero& h);
  friend Hero& operator+( Hero& h, Ammo& a) ;
  friend Hero& operator+(Hero& h, Potion& p);
 friend Hero& operator-(Hero& h, Monster& monster);



  virtual void useSpecial();
    ~Hero();
};




#endif // HERO_H_INCLUDED
