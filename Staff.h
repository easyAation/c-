#ifndef STAFF_H_INCLUDED
#define STAFF_H_INCLUDED
#include <cstdio>
class Staff
{
public:
    char num[15];
    char name[10];
    char type;
    char age[10];
    Staff *next;
    virtual void Input() = 0;
    virtual void Show() = 0;
    virtual void Updete() = 0;
    virtual void SaveRecord(FILE *fp) = 0;
    virtual void loadFile(char ch,FILE *fp) = 0;
public:
    Staff() {};
   // virtual ~Staff();
};


#endif // STAFF_H_INCLUDED
