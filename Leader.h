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
        cout << "��ţ�";
        cin >> num;
        cout << "������";
        cin >> name;
        cout << "���䣺";
        cin >> age;
        cout << "ְ��";
        cin >> job;
        cout << "���ţ�";
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
       cout<<"ԭ�ȵ�����:"<<endl;
       Show();
       cout<<"�������������"<<endl;
       Input();
    }
};

#endif // LEADER_H_INCLUDED
