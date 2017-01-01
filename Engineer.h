#ifndef ENGINEER_H_INCLUDED
#define ENGINEER_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
class Engineer: virtual public Staff
{
protected:
    char major[12];
    char prof[12];
public:
    Engineer()
    {
        type = 'E';
        next = NULL;
    }
   ~Engineer(){};
    void Input()
    {
        cout << "编号：";
        cin >> num;
        cout << "姓名：";
        cin >> name;
        cout << "年龄：";
        cin >> age;
        cout << "专业：";
        cin >> major;
        cout << "职称：";
        cin >> prof;
    }
    void Show()
    {
        cout << setw(8) << num << setw(12) << name << setw(5) << age << setw(12) << major << setw(12) << prof << endl;
    }
    void SaveRecord(FILE *fp)
    {
        fprintf(fp,"%c\n%s\n%s\n%s\n%s\n%s ",type,num,name,age,major,prof);

    }
    void loadFile(char ch,FILE *fp)
    {
        type = ch;
        fscanf(fp,"%s%s%s%s%s",num,name,age,major,prof);
        Show();
    }
    void Updete()
    {
       cout<<"原先的数据:"<<endl;
       Show();
       cout<<"请从新输入数据"<<endl;
       Input();
    }
};


#endif // ENGINEER_H_INCLUDED
