#ifndef GUN_H_INCLUDED
#define GUN_H_INCLUDED
#include"Hero.h"
using namespace std;
  class Gun {
    private:
        string name;
        int bullets;
        int damage;
        int range;

    public:
        Gun( string n, int b, int d, int r);

        string getName();

        int getBullets()  ;

        int getDamage();

        int getRange() ;

        void setBullets(int n);

    virtual void useSpecial(Hero& h1 , Object** grid);

   friend ostream& operator<<(ostream& os, const Gun& gun);


    };


#endif // GUN_H_INCLUDED
