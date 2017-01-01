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
    if( fp = fopen("d:\\staff.txt", "r"), fp == NULL) //若文件不存在
    {
        cout<<"文件不存在"<<endl;
        return ;
    }

    char aa;
    int gg = 0;
    while(fscanf(fp, "%c", &aa) != EOF)//当成功读入一个整数
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
    cout << "人员类型（e:工程师，l：领导）:";
    cin>>type;
    if(type[0] == 'e')
        p = new Engineer ,num_L++;
    else
        p = new Leader , num_E++;
    p->Input();
    p->next = head->next;
    if(p->next == NULL)
        cout<<"没错啊"<<endl;
    else
        cout<<"出错了"<<endl;
    head->next = p;


}


void StaffMange::Update()
{
    char num[10];
    cout<<"请输入编号:"<<endl;
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
    cout<<"请输入编号:"<<endl;
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
        cout<<"查无此人"<<endl ;
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
    printf("欢迎使用公司管理系统，本系统共收录Leaer:%d   Engineer:%d\n",num_L,num_E);
    printf("说明：在本系统中欲执行某功能请输入相应数字\n");
    printf("1 添加\n");
    printf("2 修改\n");
    printf("3 查找\n");
    printf("4 输出\n");
    printf("5 删除\n");
    printf("6 退出\n");

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
        case 1: 						/*添加*/
            add();
            break;
        case 2:
            Update();  break;			/*修改*/
        case 3:
            find_x();  break;           /*查找*/
        case 4:
          list_num();	break;
        case 5:
            del();      break;          /*删除*/
        case 6:
            break;

        }

    }

}
void StaffMange::Save()
{
    FILE *fp;

    Staff *p = head; //p指向首元结点
    fp = fopen("d:\\staff.txt", "w+");

    while(p->next) //当p非空，即所指结点存在
    {
        p = p->next;
        p->SaveRecord(fp);
        cout<<ftell(fp)<<" "<<sizeof(*p)<<endl;

    }
    fclose(fp);
}
