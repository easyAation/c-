#ifndef LEADER_H_INCLUDED
#define LEADER_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
class Leader:virtual public Staff
{
protected:
    char job[12];
    char dep[12];
public:
    Leader(){  type = 'L'; next = NULL;};
    virtual ~Leader(){}
    void Input()
    {
        cout << "编号：";
        cin >> num;
        cout << "姓名：";
        cin >> name;
        cout << "年龄：";
        cin >> age;
        cout << "职务：";
        cin >> job;
        cout << "部门：";
        cin >> dep;
    }
    void Show()
    {
        cout << setw(8) << num << setw(12) << name << setw(5) << age << setw(12) << job << setw(12) << dep << endl;
    }
    void SaveRecord(FILE *fp)
    {
        fprintf(fp,"%c\n%s\n%s\n%s\n%s\n%s ",type,num,name,age,job, dep);

    }
    void loadFile(char ch,FILE *fp)
    {
        type = ch;
        fscanf(fp,"%s%s%s%s%s",num,name,age,job,dep);
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

#endif // LEADER_H_INCLUDED
