#include "StaffMange.h"
#include "Engineer.h"
StaffMange::StaffMange()
{
    num_L = num_E = 0;
    head = new Engineer;
    head->next = NULL;
    load();
}

void StaffMange::load()
{
    char type;
    FILE *fp;
    if( fp = fopen("d:\\staff.txt", "r"), fp == NULL) //���ļ�������
    {
        cout<<"�ļ�������"<<endl;
        return ;
    }

    char aa;
    int gg = 0;
    while(fscanf(fp, "%c", &aa) != EOF)//���ɹ�����һ������
    {
        while(aa == ' ')
        {
              fscanf(fp,"%c",&aa);
              if(feof(fp))
                 break;
        }
        if(feof(fp))
            break;
        Staff *p;
        if(aa == 'E')
           p = new Engineer , num_E++;
        else
           p = new Leader , num_L++;
         p->loadFile(aa,fp);
         p->next = head->next;
         head->next = p;
    }

     getchar();
     getchar();
}
void StaffMange::list_num()
{
    Staff *p = head->next;
    while(p)
    {
        p->Show();
        p = p->next;
    }
    getchar();
    getchar();
}
void StaffMange::add()
{
    Staff *p;
    cout << "��Ա���ͣ�e:����ʦ��l���쵼��:";
    cin>>type;
    if(type[0] == 'e')
        p = new Engineer ,num_L++;
    else
        p = new Leader , num_E++;
    p->Input();
    p->next = head->next;
    if(p->next == NULL)
        cout<<"û��"<<endl;
    else
        cout<<"������"<<endl;
    head->next = p;


}


void StaffMange::Update()
{
    char num[10];
    cout<<"��������:"<<endl;
    cin>>num;
    Staff *p = head->next;
    while(p)
    {
        if(strcmp(p->num,num) == 0)
            break;
        p = p->next;
    }
    p->Updete();
}
Staff * StaffMange::find_x()
{
    char num[10];
    cout<<"��������:"<<endl;
    cin>>num;
    Staff *p = head;
    while(p->next)
    {
        if(strcmp(p->next->num,num) == 0)
            break;
        p = p->next;
    }

    if(p->next == NULL)
    {
        cout<<"���޴���"<<endl ;
        getchar();getchar();
        return NULL;
    }

    else
    {

        p->next->Show();
        getchar() , getchar();
        return p;
    }

}
void StaffMange::del()
{
    char num[10],flag;
    Staff *p = find_x();
    if(p == NULL)
        return ;
    Staff *t = p->next;
    p->next = t->next;
    if(t->type == 'E')
        num_E--;
    else
        num_L--;
    delete t;

}
void StaffMange::display()
{
    system("cls");
    printf("��ӭʹ�ù�˾����ϵͳ����ϵͳ����¼Leaer:%d   Engineer:%d\n",num_L,num_E);
    printf("˵�����ڱ�ϵͳ����ִ��ĳ������������Ӧ����\n");
    printf("1 ���\n");
    printf("2 �޸�\n");
    printf("3 ����\n");
    printf("4 ���\n");
    printf("5 ɾ��\n");
    printf("6 �˳�\n");

}
void StaffMange::userkey()
{
    int select;
    while(true)
    {
        display();
        scanf("%d",&select);
        if(select == 7)
            break;
        switch(select)
        {
        case 1: 						/*���*/
            add();
            break;
        case 2:
            Update();  break;			/*�޸�*/
        case 3:
            find_x();  break;           /*����*/
        case 4:
          list_num();	break;
        case 5:
            del();      break;          /*ɾ��*/
        case 6:
            break;

        }

    }

}
void StaffMange::Save()
{
    FILE *fp;

    Staff *p = head; //pָ����Ԫ���
    fp = fopen("d:\\staff.txt", "w+");

    while(p->next) //��p�ǿգ�����ָ������
    {
        p = p->next;
        p->SaveRecord(fp);
        cout<<ftell(fp)<<" "<<sizeof(*p)<<endl;

    }
    fclose(fp);
}
