#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED
#include<iostream>
using namespace std;
class Object {
protected:
    char type;
public:
    Object()=default;
    Object(char t);
    char getType();
    void setType(char t);

    friend ostream& operator<<(ostream& os,  Object& obj);
    virtual  ~Object();
};


#endif // OBJECT_H_INCLUDED
