#ifndef STAFFMANGE_H_INCLUDED
#define STAFFMANGE_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Staff.h"
#include "Leader.h"
#include "Engineer.h"
using namespace std;
class StaffMange
{
public:
    int num_L , num_E;
    Staff *head;
    char type[10];
    StaffMange();
    void load();
    void add();
    void Save();
    void Update();
    void display();
    void userkey();
    void list_num();
    void del();

    Staff * find_x();
};

#endif // STAFFMANGE_H_INCLUDED
