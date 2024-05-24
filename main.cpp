#include <iostream>
#include"Character.h"
#include"object.h"
#include"Gun.h"
#include "Hero.h"
#include "Pistol.h"
#include "Rifle.h"
#include "Bazooka.h"
#include "Monster.h"
#include "MedicHero.h"
#include "DemolitionHero.h"
#include "GhostMonster.h"
#include "TankMonster.h"
#include "Item.h"
#include "Ammo.h"
#include "Potion.h"
#include <ctime>
#include <limits>
#include <string>
class Game;


using namespace std;
//Object
Object::Object(char t){
    this->type=t;
}

char Object::getType()   {
    return type;
}

void Object::setType(char t){
this->type=t;
}


Object::~Object(){
}
ostream& operator<<(ostream& os,  Object& obj) {
    os << "Object Type " << obj.getType();
    return os;

}

//Gun
Gun:: Gun( string n, int b, int d, int r) : name(n), bullets(b), damage(d), range(r) {};

string Gun:: getName() {
            return name;
        }

int Gun:: getBullets()  {
            return bullets;
        }

int Gun:: getDamage()  {
            return damage;
        }

int Gun:: getRange()  {
            return range;
        }

void Gun::setBullets(int n){
    this->bullets=n;
}

   ostream& operator<<(ostream& os, const Gun& gun) {
    os << "Name: " << gun.name << ", Bullets: " << gun.bullets << ", Damage: " << gun.damage << ", Range: " << gun.range;
    return os;
}

void Gun::useSpecial(Hero& h1 , Object** grid){};


//Character

Character::Character(char t, int x, int y, int hp) : Object(t), positionX(x), positionY(y), healthPoints(hp) {}


int Character::getPositionX() {
    return positionX;
}

int Character::getPositionY() {
    return positionY;
}

int Character::getHealthPoints() {
    return healthPoints;
}


void Character::setPosition(int x, int y) {
    positionX = x;
    positionY = y;
}

void Character::setHealthPoints(int hp) {
    healthPoints = hp;
}

//HERO

Hero::Hero(char t, int x, int y, int hp) : Character(t, x, y, hp), weapon(nullptr) {}


Gun* Hero::getWeapon() {
    return this->weapon;
}

void Hero::setWeapon(Gun* g) {
    weapon = g;
}

  ostream& operator<<(ostream& os, const Hero& h){
os << "Hero Type: " << h.type << ", X: " << h.positionX << ", Y: " << h.positionX << ", HP: " << h.healthPoints<<endl;
os<<"Weapon 1: "<<*(h.weapon)<<endl;
    return os;

 }


 Hero& operator+( Hero& h, Ammo& a) {
     h.weapon->setBullets(h.weapon->getBullets()+a.getBullets());
     return h;


 }
 Hero& operator+(Hero& h, Potion& p) {
    h.setHealthPoints(h.getHealthPoints()+p.getHealingAmount());
    return h;

}

   Hero& operator-(Hero& h, Monster& monster){
       int damage=20;
       Monster* m = &monster;
       TankMonster* tm =dynamic_cast<TankMonster*>(m);
       if(tm){
                    int s=tm->getShield();

                    if(s>=damage){
                        s=s-damage;
                        damage=0;
                    }


                    else{

                        damage=damage-s;
                        s=0;
                        if(damage<0){
                            damage=0;

                        }
                    }
                     tm->setShield(s);



                  }
       h.healthPoints-=10;
       monster.setHealthPoints(monster.getHealthPoints()-damage);
       return h;
   }


        // Ensure health points do not go below zero




 void Hero::useSpecial(){
 }


Hero::~Hero() {
    delete weapon;
}

void pistolSpecial(Hero& h1 ,Object* grid[15][15],char direction){
            bool monsterFound=false;
            int posX=h1.getPositionX();
            int posY=h1.getPositionY();
            int range = h1.getWeapon()->getRange();
            int damage=h1.getWeapon()->getDamage();
             Monster* m;
            if(direction=='W'|| direction=='w'){
                    int startPos=posX-1;
                    for(int j=0;j<range;j++){
                            if(startPos>14 || startPos<0){
                                break;
                            }
                            else{

                         m =dynamic_cast<Monster*>(grid[startPos][posY]);
                        if(m){
                            monsterFound=true;
                            break;
                        }
                    else{
                            startPos--;

                    }
                    }


                    }


                if(monsterFound==true){
                TankMonster* tm =dynamic_cast<TankMonster*>(m);
                  if(tm){
                    int s=tm->getShield();

                    if(s>=damage){
                        s=s-damage;
                        damage=0;
                    }


                    else{

                        damage=damage-s;
                        s=0;
                        if(damage<0){
                            damage=0;

                        }
                    }
                     tm->setShield(s);



                  }
                  Monster* m =dynamic_cast<Monster*>(grid[startPos][posY]);

                    m->setHealthPoints(m->getHealthPoints()-damage);

                }


            }
            else if(direction=='S'|| direction=='s'){
                    int startPos=posX+1;
                    for(int j=0;j<range;j++){
                             if(startPos>14 || startPos<0){
                                break;
                            }
                            else{

                         m =dynamic_cast<Monster*>(grid[startPos][posY]);
                        if(m){
                            monsterFound=true;
                            break;
                        }
                    else{
                            startPos++;

                    }

                            }
                    }

                 if(monsterFound==true){
                    TankMonster* tm =dynamic_cast<TankMonster*>(m);
                  if(tm){
                    int s=tm->getShield();

                    if(s>=damage){
                        s=s-damage;
                        damage=0;
                    }


                    else{

                        damage=damage-s;
                        s=0;
                        if(damage<0){
                            damage=0;

                        }
                    }
                     tm->setShield(s);



                  }
                  Monster* m =dynamic_cast<Monster*>(grid[startPos][posY]);

                    m->setHealthPoints(m->getHealthPoints()-damage);

                }



            }
            else if(direction=='D'|| direction=='d'){
                  int startPos=posY+1;
                    for(int j=0;j<range;j++){
                            if(startPos>14 || startPos<0){
                                break;
                            }
                            else{

                         m =dynamic_cast<Monster*>(grid[posX][startPos]);
                        if(m){
                            monsterFound=true;
                            break;
                        }
                    else{
                            startPos++;

                    }


                    }
                    }

                 if(monsterFound==true){
                         TankMonster* tm =dynamic_cast<TankMonster*>(m);
                  if(tm){
                    int s=tm->getShield();

                    if(s>=damage){
                        s=s-damage;
                        damage=0;
                    }


                    else{

                        damage=damage-s;
                        s=0;
                        if(damage<0){
                            damage=0;

                        }
                    }
                     tm->setShield(s);



                  }
                 Monster* m =dynamic_cast<Monster*>(grid[posX][startPos]);
                    m->setHealthPoints(m->getHealthPoints()-damage);

                }



            }


            else if(direction=='A'|| direction=='a'){
                   int startPos=posY-1;
                    for(int j=0;j<range;j++){
                             if(startPos>14 || startPos<0){
                                break;
                            }
                            else{

                         m =dynamic_cast<Monster*>(grid[posX][startPos]);
                        if(m){
                            monsterFound=true;

                            break;
                        }
                    else{
                            startPos--;

                    }
                            }

                    }

                 if(monsterFound==true){
                         TankMonster* tm =dynamic_cast<TankMonster*>(m);
                  if(tm){
                    int s=tm->getShield();

                    if(s>=damage){
                        s=s-damage;
                        damage=0;
                    }


                    else{

                        damage=damage-s;
                        s=0;
                        if(damage<0){
                            damage=0;

                        }
                    }
                     tm->setShield(s);



                  }

                  Monster* m =dynamic_cast<Monster*>(grid[posX][startPos]);
                    m->setHealthPoints(m->getHealthPoints()-damage);

                }



            }
}

// pistol
Pistol::Pistol() : Gun("Pistol", 16, 30, 2) {}

void Pistol::useSpecial(Hero& h1 ,Object* grid[15][15]){
    pistolSpecial( h1 ,grid,'W');
    pistolSpecial( h1 ,grid,'S');
    pistolSpecial( h1 ,grid,'A');
    pistolSpecial( h1 ,grid,'D');
    h1.getWeapon()->setBullets( h1.getWeapon()->getBullets()-4);


}

//rifle
Rifle::Rifle() : Gun("Rifle", 30, 20, 4) {}

void Rifle::useSpecial(Hero& h1 , Object* grid[15][15]){
        int posX=h1.getPositionX();
        int posY=h1.getPositionY();
        int range = h1.getWeapon()->getRange();
        int damage=h1.getWeapon()->getDamage();
        //UP
        int startPos=posX-1;
        for(int i=0;i<range;i++){
            if(i>14 ||i<0){
                break;
            }
            else{
                Monster* m =dynamic_cast<Monster*>(grid[startPos][posY]);
                TankMonster* tm =dynamic_cast<TankMonster*>(m);
                 if(tm){
                    int s=tm->getShield();

                    if(s>=damage){
                        s=s-damage;
                        damage=0;
                    }


                    else{

                        damage=damage-s;
                        s=0;
                        if(damage<0){
                            damage=0;

                        }
                    }
                     tm->setShield(s);



                  }

                if(m)
                    m->setHealthPoints(m->getHealthPoints()-damage);


            }
            startPos--;
        }
        //Left
        startPos=posY-1;
         for(int i=0;i<range;i++){
            if(i>14 ||i<0){
                break;
            }
            else{
                Monster* m =dynamic_cast<Monster*>(grid[posX][startPos]);
                  TankMonster* tm =dynamic_cast<TankMonster*>(m);
                 if(tm){
                    int s=tm->getShield();

                    if(s>=damage){
                        s=s-damage;
                        damage=0;
                    }


                    else{

                        damage=damage-s;
                        s=0;
                        if(damage<0){
                            damage=0;

                        }
                    }
                     tm->setShield(s);



                  }
                if(m)
                    m->setHealthPoints(m->getHealthPoints()-damage);


            }
            startPos--;
        }
        //Right
        startPos=posY+1;
        for(int i=0;i<range;i++){
            if(i>14 ||i<0){
                break;
            }
            else{
                Monster* m =dynamic_cast<Monster*>(grid[posX][startPos]);
                  TankMonster* tm =dynamic_cast<TankMonster*>(m);
                 if(tm){
                    int s=tm->getShield();

                    if(s>=damage){
                        s=s-damage;
                        damage=0;
                    }


                    else{

                        damage=damage-s;
                        s=0;
                        if(damage<0){
                            damage=0;

                        }
                    }
                     tm->setShield(s);



                  }
                if(m)
                    m->setHealthPoints(m->getHealthPoints()-damage);


            }
            startPos++;
        }

         h1.getWeapon()->setBullets(h1.getWeapon()->getBullets()-3);



}

//bazooka
Bazooka::Bazooka() : Gun("Bazooka", 4, 150, 8) {}


void Bazooka::useSpecial(Hero & h1, Object* grid[15][15]) {
    bool xDiagonal;
    bool oDiagonal;
    int xPos=h1.getPositionX();
    int yPos=h1.getPositionY();
    if(xPos==yPos ){
        xDiagonal=true;
    }
    else if(xPos+yPos==14){
        oDiagonal=true;
    }

    if(xDiagonal){
        for(int i =0;i<15;i++){
             Monster* m =dynamic_cast<Monster*>(grid[i][i]);
             if(m)
            grid[i][i]=new Object('.');
        }
    }

    if(oDiagonal){
           int y=14;
        for(int i =0;i<15;i++){
             Monster* m =dynamic_cast<Monster*>(grid[i][y]);
             if(m){
                  grid[i][i]=new Object('.');
                  y--;
             }

        }
    }

}



//Monster
Monster::Monster(char t, int x, int y, int hp) : Character(t, x, y, hp) {}



//MedicHero
MedicHero::MedicHero(char t, int x, int y, int hp, int ha) : Hero(t, x, y, hp), healingAmount(ha) {}

int MedicHero::getHealingAmount() {
    return healingAmount;
}
    void MedicHero::useSpecial(){
    static bool hasRun = false;
    if(!hasRun){
            this->setHealthPoints(this->getHealthPoints()+this->getHealingAmount());
            hasRun=true;


}
}


  ostream& operator<<(ostream& os,  MedicHero& h){
os << "Hero Type: " << h.type << ", X: " << h.positionX << ", Y: " << h.positionX << ", HP: " << h.healthPoints<<endl;
os<<"Weapon 1: "<<*(h.getWeapon())<<endl;
os<<"Healing Amount:"<<h.healingAmount<<endl;
    return os;

 }






//DemolitionHero
DemolitionHero::DemolitionHero(char t, int x, int y, int hp) : Hero(t, x, y, hp) {}

void DemolitionHero::setWeapon2(Gun *g ){
    this->weapon2=g;
}

Gun* DemolitionHero::getWeapon2(){
    return weapon2;
}


 ostream& operator<<(ostream& os,  DemolitionHero& h){
 os << "Hero Type: " << h.type << ", X: " << h.positionX << ", Y: " << h.positionX << ", HP: " << h.healthPoints<<endl;
 os<<"Weapon 1: "<<*(h.getWeapon())<<endl;
 os<<"weapon 2: "<<*(h.getWeapon2())<<endl;
    return os;
 }


 Hero& operator+( DemolitionHero& h, Ammo& a) {
     h.getWeapon()->setBullets(h.getWeapon()->getBullets()+a.getBullets());
     h.getWeapon2()->setBullets(h.getWeapon2()->getBullets()+a.getBullets());
        return h;

 }



 void DemolitionHero::useSpecial(){
    Gun* tempGun = getWeapon();
    DemolitionHero::setWeapon(getWeapon2());
    DemolitionHero::setWeapon2(tempGun);

}

//GhostMonster
GhostMonster::GhostMonster(char t, int x, int y, int hp) : Monster(t, x, y, hp), isVisible(true) {}

bool GhostMonster::isVisibleOnMap()  {
    return isVisible;
}

void GhostMonster::setVisibility(bool v){
    isVisible=v;
}

//TankMonster
TankMonster::TankMonster(char t, int x, int y, int hp, int s) : Monster(t, x, y, hp), shield(s) {}

int TankMonster::getShield() const {
    return shield;
}
void TankMonster::setShield(int s){
    shield=s;
}


//Item


Item::Item(char t) : Object(t) {}

//Ammo

Ammo::Ammo(int b) : Item('A'), bullets(b) {}

int Ammo::getBullets()  {
    return bullets;
}


//Potion

Potion::Potion(int ha) : Item('P'), healingAmount(ha) {}

int Potion::getHealingAmount() const {
    return healingAmount;
}


// Game class
class Game {
private:
    static const int rows = 15;
    static const int cols = 15;
     int round=1;
    bool ghost_Visible;
    bool hero_outOFBounds=false;
    int ghostC=0;
    int respawnC=1;
    string s;
    string s2;
    string s3;
    Object* grid[rows][cols];
    Hero* hero;

public:
    Game() {
        hero = NULL;

        // Initialize grid with empty objects
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                grid[i][j] = new Object('.');
            }
        }
    }

    ~Game() {
        // Deallocate memory for grid objects
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                delete grid[i][j];
            }
        }
        // Deallocate memory for hero object
        delete hero;
    }

    void generateMap() {
        srand(time(0));

        // Generate health potions
        for (int i = 0; i < 5; i++) {
            int healingAmount = rand() % 41 + 10;  // Random number between 10 and 50
            grid[rand() % rows][rand() % cols] = new Potion(healingAmount);
        }

        // Generate ammo
        for (int i = 0; i < 10; i++) {
            int bullets = rand() % 16 + 5;  // Random number between 5 and 20
            grid[rand() % rows][rand() % cols] = new Ammo(bullets);
        }

        // Generate monsters

         int monsterCount = 5;
         int monsterHPRange = 10;
         int monsterHPMin = 60;

            for (int j = 0; j < monsterCount; j++) {
                int hp = (rand() % monsterHPRange + 1) * monsterHPMin;
                int x= (rand() % rows);
                int y=(rand() % cols);
                grid[x][y] = new TankMonster('T', x, y, hp,hp);
            }

            for (int j = 0; j < monsterCount; j++) {
                int hp = (rand() % monsterHPRange + 1) * monsterHPMin;
                int x= (rand() % rows);
                int y=(rand() % cols);
                grid[x][y] = new GhostMonster('G', x, y, hp);
            }

    }

    void showMap()  {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << grid[i][j]->getType() << " ";
            }
            cout << endl;
        }
    }

    void startGame() {
        int heroType;
        int gunType;
        int gun2Type;
        cout<<"GAME START"<<endl;
        cout << "Please enter 1 to choose Demolition or 2 to choose Medic: ";
        cin >> heroType;

        cout << "Please enter 1 for Pistol, 2 for Bazooka, or 3 for Rifle: ";
        cin >> gunType;
        if(heroType==1){
        cout << "Please enter 1 for Pistol, 2 for Bazooka, or 3 for Rifle: ";
        cin >> gun2Type;
        }

        if (heroType == 1) {
            if (gunType == 1) {
                Pistol* p = new Pistol();
                hero = new DemolitionHero('D', 0, 0, 100);
                hero->setWeapon(p);

            } else if (gunType == 2) {
                Bazooka* b = new Bazooka();
                hero = new DemolitionHero('D', 0, 0, 100);
                hero->setWeapon(b);
            } else if (gunType == 3) {

                Rifle* r = new Rifle();
                hero = new DemolitionHero('D', 0, 0, 100);
                hero->setWeapon(r);
            }

            if (gun2Type == 1) {
                Pistol* p = new Pistol();
        DemolitionHero* Dh =dynamic_cast<DemolitionHero*>(hero);

            Dh->setWeapon2(p);
            } else if (gun2Type == 2) {
                Bazooka* b = new Bazooka();
    DemolitionHero* Dh =dynamic_cast<DemolitionHero*>(hero);
            Dh->setWeapon2(b);
            } else if (gun2Type == 3) {

                Rifle* r = new Rifle();
        DemolitionHero* Dh =dynamic_cast<DemolitionHero*>(hero);
        Dh->setWeapon2(r);
            }


        } else if (heroType == 2) {
            if (gunType == 1) {
                Pistol* p = new Pistol();
                hero = new MedicHero('M', 0, 0, 100,50);
            hero->setWeapon(p);
            } else if (gunType == 2) {
                Bazooka* b = new Bazooka();
                hero = new MedicHero('M', 0, 0, 100,50);
                hero->setWeapon(b);
            } else if (gunType == 3) {

                Rifle* r = new Rifle();
                hero = new MedicHero('M', 0, 0, 100,50);
                hero->setWeapon(r);
            }
        }

        generateMap();
        grid[0][0] = hero;
        hero->setPosition(0,0);



        while(true){
                updateMap();
                playRound();
                int n= checkGameOver();
                if(n==0){
                    cout<<"HERO LOST"<<endl;
                    cout<<"GAME OVER!"<<endl;
                    break;
                }
                else if(n==1){
                    cout<<"HERO Survived"<<endl;
                    cout<<"GAME WON!"<<endl;
                    break;

                }

            }


    }

    void playRound(){
        int option;
        char direction;
        cout<<"CHOOSE ACTION!"<<endl;
        cout<<"(1)->Move"<<endl;
        cout<<"(2)->Use Weapon"<<endl;
        cout<<"(3)->Use Weapon's special ability"<<endl;
        cout<<"(4)->Use Hero's special ability"<<endl;
        while(true){


         try{
         if (!(cin >> option)) {

            throw invalid_argument("Invalid input. Please enter a valid Input.");
        }

        if(option>4 || option < -1){
            throw invalid_argument("Invalid input. Please enter a valid integer.");
        }

        break;



    } catch (const std::invalid_argument& e) {

        cout << e.what() << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }


        }





            if(option==1){
              cout<<"Choose Direction"<<endl<<"  W  "<<endl<<"A S D"<<endl;

        while(true){
                cin>>direction;


         try{
         if (!(direction=='W' || direction=='w' || direction=='s' || direction=='S' || direction=='a' || direction=='A' || direction=='d' || direction=='D')  ) {

            throw invalid_argument("Invalid input. Please enter a valid Input.");
        }


        break;



    } catch (const std::invalid_argument& e) {

        cout << e.what() << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }


        }


                heroMove(*hero,direction);
                if(!hero_outOFBounds)
                    roundIncrement();







            }
            else if(option==2){
                    cout<<"Choose Direction"<<endl<<"  W  "<<endl<<"A S D"<<endl;
                     while(true){



         try{
             cin>>direction;

         if (!(direction=='W' || direction=='w' || direction=='s' || direction=='S' || direction=='a' || direction=='A' || direction=='d' || direction=='D')  ) {

            throw invalid_argument("Invalid input. Please enter a valid Input.");
        }


        break;



    } catch (const std::invalid_argument& e) {

        cout << e.what() << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }


        }
                FireGun(direction);
                roundIncrement();

            }
            else if(option==3){
                    useGunSpecial();
                    roundIncrement();

                   }




            else if(option==4){
                    hero->useSpecial();
                    roundIncrement();
                    s="HERO SPECIAL ABILITY USED";




            }


    }

    void roundIncrement(){
            round++;
            ghostC++;
            respawnC++;

    }



    bool checkMove(int posX,int posY, char direction){
            hero_outOFBounds=false;
            if(posX >15 || posX<0 || posY >15 || posY <0){
                    hero_outOFBounds=true;
                    s="OUT OF BOUNDS";


                return false;
            }

            Monster* m = dynamic_cast<Monster*>(grid[posX][posY]);
            TankMonster* tm = dynamic_cast<TankMonster*>(m);
             Potion* p = dynamic_cast<Potion*>(grid[posX][posY]);
              Ammo* a = dynamic_cast<Ammo*>(grid[posX][posY]);
                if(m){


                      *hero-*m;
                      s2="MONSTER THERE";

                        return false;

                }



                else if(p){

                        *hero+*p;
                        s2="POTION PICKED UP ";

                     return true;
                }
                  else if(a){
                    DemolitionHero* dh = dynamic_cast<DemolitionHero*>(hero);
                    MedicHero* mh=dynamic_cast<MedicHero*>(hero);
                    if(dh){
                        *dh+*a;
                         s2="AMMO PICKED UP ";
                    }
                    else if(mh){
                         *mh+*a;
                          s2="AMMO PICKED UP ";
                    }


                     return true;
                }


                else {
                     return true;
                }



    }





    void heroMove(Hero& h1 , char direction){

        if(direction=='W' || direction=='w'){
                int posX=h1.getPositionX()-1;
                int posY=h1.getPositionY();
                if(checkMove(posX,posY, direction)){
                        grid[h1.getPositionX()][h1.getPositionY()]=new Object('.');
                        grid[posX][posY]=hero;
                        h1.setPosition(posX,posY);
                        s="MOVE UP";

                }

        }
        else if(direction=='S' || direction=='s'){
                int posX=h1.getPositionX()+1;
                int posY=h1.getPositionY();
                if(checkMove(posX,posY, direction)){
                    grid[h1.getPositionX()][h1.getPositionY()]=new Object('.');
                        grid[posX][posY]=hero;
                        h1.setPosition(posX,posY);
                        s="MOVE DOWN";

                }

        }
        else if(direction=='D' || direction=='d'){
                int posX=h1.getPositionX();
                int posY=h1.getPositionY()+1;
                if(checkMove(posX,posY, direction)){
                        grid[h1.getPositionX()][h1.getPositionY()]=new Object('.');
                        grid[posX][posY]=hero;
                        h1.setPosition(posX,posY);

                        s="MOVE RIGHT";
                }

        }
        else if(direction=='A' || direction=='a'){
                int posX=h1.getPositionX();
                int posY=h1.getPositionY()-1;
                if(checkMove(posX,posY, direction)){
                        grid[h1.getPositionX()][h1.getPositionY()]=new Object('.');
                        grid[posX][posY]=hero;
                        h1.setPosition(posX,posY);
                        s="MOVE LEFT";

                }

        }
    }
    bool checkMonsters(){
        for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            Monster* m = dynamic_cast<Monster*>(grid[i][j]);
            if(m){
                return false;
            }

        }

    }
     return true;



    }

    void deleteMonsters(){
        for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
        Monster* m = dynamic_cast<Monster*>(grid[i][j]);
        if(m){
            if(m->getHealthPoints()<=0)
             grid[i][j]=new Object('.');


        }


            }

        }
    }

    int checkGameOver(){

        if(hero->getHealthPoints()==0){
            return 0;
        }

        else if(checkMonsters()){
                return 1;

        }
        else
            return -1;


    }


    void FireGun(char direction){
        if(hero->getWeapon()->getBullets()>=1){
            bool monsterFound=false;
            int posX=hero->getPositionX();
            int posY=hero->getPositionY();
            int range = hero->getWeapon()->getRange();
            int damage=hero->getWeapon()->getDamage();
            if(direction=='W'|| direction=='w'){
                    int startPos=posX-1;
                    for(int j=0;j<range;j++){
                            if(startPos>14 || startPos<=0){
                                break;
                            }
                            else{

                        Monster* m =dynamic_cast<Monster*>(grid[startPos][posY]);
                        if(m){
                            monsterFound=true;
                            break;
                        }
                    else{
                            startPos--;

                    }
                    }


                    }


                if(monsterFound==true){
                  Monster* m =dynamic_cast<Monster*>(grid[startPos][posY]);
                  TankMonster* tm =dynamic_cast<TankMonster*>(m);
                  if(tm){
                    int s=tm->getShield();

                    if(s>=damage){
                        s=s-damage;
                        damage=0;
                    }


                    else{

                        damage=damage-s;
                        s=0;
                        if(damage<0){
                            damage=0;

                        }
                    }
                     tm->setShield(s);
                     s3="SHIELD:"+to_string(s);


                  }







                    int hp_before=m->getHealthPoints();
                    m->setHealthPoints(m->getHealthPoints()-damage);
                    int hp_after=m->getHealthPoints();
                   s="FIRE GUN!! \nMonster HIT!";
                   s2="HP Before: "+to_string(hp_before)+"\n"+"HP After: "+to_string(hp_after) +"\n";
                   if(hp_after<=0){
                    s2="MONSTER DEAD";
                   }

                }
                else{
                     s="FIRE GUN!! \nNo monster in range";
                }

                hero->getWeapon()->setBullets(hero->getWeapon()->getBullets()-1);



            }
            else if(direction=='S'|| direction=='s'){
                    int startPos=posX+1;
                    for(int j=0;j<range;j++){

                        Monster* m =dynamic_cast<Monster*>(grid[startPos][posY]);
                        if(m){
                            monsterFound=true;
                            break;
                        }
                    else{
                            startPos++;

                    }


                    }

                 if(monsterFound==true){
                  Monster* m =dynamic_cast<Monster*>(grid[startPos][posY]);
                  TankMonster* tm =dynamic_cast<TankMonster*>(m);
                  if(tm){
                    int s=tm->getShield();

                    if(s>=damage){
                        s=s-damage;
                        damage=0;
                    }


                    else{

                        damage=damage-s;
                        s=0;
                        if(damage<0){
                            damage=0;

                        }
                    }
                     tm->setShield(s);
                     s3="SHIELD:"+to_string(s);


                  }







                    int hp_before=m->getHealthPoints();
                    m->setHealthPoints(m->getHealthPoints()-damage);
                    int hp_after=m->getHealthPoints();
                   s="FIRE GUN!! \nMonster HIT!";
                   s2="HP Before: "+to_string(hp_before)+"\n"+"HP After: "+to_string(hp_after) +"\n";
                   if(hp_after<=0){
                    s2="MONSTER DEAD";
                   }
                }
                else{
                     s="FIRE GUN!! \nNo monster in range";
                }

                hero->getWeapon()->setBullets(hero->getWeapon()->getBullets()-1);

            }
            else if(direction=='D'|| direction=='d'){
                  int startPos=posY+1;
                    for(int j=0;j<range;j++){
                            if(startPos>14 || startPos<=0){
                                break;
                            }
                            else{

                        Monster* m =dynamic_cast<Monster*>(grid[posX][startPos]);
                        if(m){
                            monsterFound=true;
                            break;
                        }
                    else{
                            startPos++;

                    }


                    }
                    }

                  if(monsterFound==true){
                 Monster* m =dynamic_cast<Monster*>(grid[posX][startPos]);
                  TankMonster* tm =dynamic_cast<TankMonster*>(m);
                  if(tm){
                    int s=tm->getShield();

                    if(s>=damage){
                        s=s-damage;
                        damage=0;
                    }


                    else{

                        damage=damage-s;
                        s=0;
                        if(damage<0){
                            damage=0;

                        }
                    }
                     tm->setShield(s);
                     s3="SHIELD:"+to_string(s);


                  }







                    int hp_before=m->getHealthPoints();
                    m->setHealthPoints(m->getHealthPoints()-damage);
                    int hp_after=m->getHealthPoints();
                   s="FIRE GUN!! \nMonster HIT!";
                   s2="HP Before: "+to_string(hp_before)+"\n"+"HP After: "+to_string(hp_after) +"\n";
                   if(hp_after<=0){
                    s2="MONSTER DEAD";
                   }
                }
                else{
                     s="FIRE GUN!! \nNo monster in range";
                }

                hero->getWeapon()->setBullets(hero->getWeapon()->getBullets()-1);

            }


            else if(direction=='A'|| direction=='a'){
                   int startPos=posY-1;
                    for(int j=0;j<range;j++){

                        Monster* m =dynamic_cast<Monster*>(grid[posX][startPos]);
                        if(m!=nullptr){
                            monsterFound=true;

                            break;
                        }
                    else{
                            startPos--;

                    }


                    }

                  if(monsterFound==true){
                  Monster* m =dynamic_cast<Monster*>(grid[posX][startPos]);
                  TankMonster* tm =dynamic_cast<TankMonster*>(m);
                  if(tm){
                    int s=tm->getShield();

                    if(s>=damage){
                        s=s-damage;
                        damage=0;
                    }


                    else{

                        damage=damage-s;
                        s=0;
                        if(damage<0){
                            damage=0;

                        }
                    }
                     tm->setShield(s);
                     s3="SHIELD:"+to_string(s);


                  }







                    int hp_before=m->getHealthPoints();
                    m->setHealthPoints(m->getHealthPoints()-damage);
                    int hp_after=m->getHealthPoints();
                   s="FIRE GUN!! \nMonster HIT!";
                   s2="HP Before: "+to_string(hp_before)+"\n"+"HP After: "+to_string(hp_after) +"\n";
                   if(hp_after<=0){
                    s2="MONSTER DEAD";
                   }
                }
                else{
                     s="FIRE GUN!! \nNo monster in range";
                }

                hero->getWeapon()->setBullets(hero->getWeapon()->getBullets()-1);
            }









        }
       else {
            s="NO ENOUGH AMMO";

        }

    }


    void spawnMonster(){
         int monsterHPRange = 10;
         int monsterHPMin = 60;
        while(true)
        {   int x= (rand() % rows);
            int y=(rand() % cols);
             Object* o = dynamic_cast<Object*>(grid[x][y]);
                if(o)
                if(o->getType()=='.'){
                         int hp = (rand() % monsterHPRange + 1) * monsterHPMin;
                        grid[x][y]=new TankMonster('T',x,y,hp,hp);
                        break;

                }


        }

        while(true){
                int x= (rand() % rows);
            int y=(rand() % cols);
             Object* o = dynamic_cast<Object*>(grid[x][y]);
                if(o)
                if(o->getType()=='.'){
                         int hp = (rand() % monsterHPRange + 1) * monsterHPMin;
                        grid[x][y]=new GhostMonster('T',x,y,hp);
                        break;

                }


        }
    s="NEW MONSTERS SPAWNED";

    }

    void useGunSpecial() {
        Rifle* r = dynamic_cast<Rifle*>(hero->getWeapon());
        Bazooka* b = dynamic_cast<Bazooka*>(hero->getWeapon());
        Pistol* p = dynamic_cast<Pistol*>(hero->getWeapon());
                   if(r){
                      if(hero->getWeapon()->getBullets()>=3){
                        r->useSpecial(*hero,grid);
                    s="RIFLE SPECIAL ABILITY!!";
                      }
                    else{
                    s="NO ENOUGH AMMO TO USE SPECIAL ABILITY";
                   }
                   }

                    if(b){
                        if(hero->getPositionX()==hero->getPositionY()  || (hero->getPositionX()+hero->getPositionY()==14 )){
                             b->useSpecial(*hero,grid);
                              s="Bazooka SPECIAL ABILITY!!";
                           }
                           else{
                            s="HERO NOT IN A DIAGONAL CELL";

                   }


                   }
                    if(p){
                        if(hero->getWeapon()->getBullets()>=4){
                                  p->useSpecial(*hero,grid);
                                  s="PISTOL SPECIAL ABILITY!!";

                        }
                        else{
                            s="NO ENOUGH AMMO TO USE SPECIAL ABILITY";
                        }


                   }







    }




void Ghost_disappear(){
        for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            GhostMonster* gm = dynamic_cast<GhostMonster*>(grid[i][j]);
            if(gm){
                gm->setType('.');
                gm->setVisibility(false);
            }


    }
        }
    }

void Ghost_appear(){

         for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
           GhostMonster* gm = dynamic_cast<GhostMonster*>(grid[i][j]);
           if(gm)
            if(gm->isVisibleOnMap()==false)
                gm->setType('G');

    }
        }

    }

 void printDetails(){
        cout<<"Round: "<<round<<endl;
        DemolitionHero* dh = dynamic_cast<DemolitionHero*>(hero);
        MedicHero* mh = dynamic_cast<MedicHero*>(hero);
        if(dh){
            cout<<*dh<<endl;
        }
        else if(mh){
             cout<<*mh<<endl;
        }




    }

void updateMap(){
        deleteMonsters();
        if(ghostC==3){
            if(ghost_Visible==true){
            Ghost_disappear();
            ghost_Visible=false;
            }
            else{
            Ghost_appear();
            ghost_Visible=true;
            }

            ghostC=0;
        }

        if(respawnC==20){
            spawnMonster();
            respawnC=1;


        }

        system("cls");
        showMap();
        printDetails();
        cout<<s<<endl;
        cout<<s2<<endl;
        cout<<s3<<endl;
        s="";
        s2="";
        s3="";



    }




};




int main() {

    Game game;

     game.startGame();


    return 0;
}










