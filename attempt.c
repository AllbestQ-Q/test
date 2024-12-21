#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define X (RR*)malloc(sizeof(RR))
#define Y (TT*)malloc(sizeof(TT))
#define Z (EE*)malloc(sizeof(EE))
//定义结构体
typedef struct car
{
    int id;
    char che_pai[10];
    char che_xing[40];
    int number;
    int seat;
    float day_price;
    float month_price;
    int rent;
    struct car *next;
}RR;
typedef struct client
{
    char name[20];
    char id[20];
    char license[20];
    char phone[15];
    char workplace[40];
    char address[40];
    struct client *next;
}TT;
typedef struct trade
{
    char name[20];
    char id[20];//身份证。
    char id_car[20];//车辆编号。
    char che_pai[10];
    int number;//车的数量。
    char type[6];//日租或包月。
    int term;//租期。
    int start_day;
    float deposit;//押金。
    float money1;//应交租金。
    int end_day;
    float money2;//实收租金。
    struct trade *next;
}EE;
//函数列表
RR *file1();
TT *file2();
EE *file3();
void file1_w();
void file2_w();
void menu1();
void menu2();
void menu2_1();
void menu2_2();
void menu2_2_1();
void menu3();
void menu3_1();
void menu3_2();
void menu4();

int printf_(RR *s,int flag);
void car_creat(RR *head1);
void car_add(RR *head1);
void car_delete(RR *head1);
void car_modify(RR *head1);
void car_query(RR *head1);
void car_query1(RR *head1);
void car_query2(RR *head1);
void car_query3(RR *head1);
void car_query4(RR *head1);
void car_query5(RR *head1);
void car_display(RR *head1);

int printf_2(TT *s,int flag);
void client_creat(TT *head2);
void client_add(TT *head2);
void client_delete(TT *head2);
void client_modify(TT *head2);
void client_query(TT *head2);
void client_query1(TT *head2);
void client_query2(TT *head2);
void client_query3(TT *head2);
void client_query4(TT *head2);
void client_query5(TT *head2);
void client_display(TT *head2);
//函数定义
RR *file1()
{
    int id;
    char che_pai[10];
    char che_xing[40];
    int number;
    int seat;
    float day_price;
    float month_price;
    int rent;
    FILE *fp;
    fp=fopen("car_message.txt","r");
    RR *head1,*s,*r;
    r=head1;
    while(fscanf("%d %s %s %d %d %f %f %d",&id,che_pai,che_xing,&number,
                  &seat,&day_price,&month_price,&rent)==8)
    {
        s=X;//分配动态存储空间。
        s->id=id;
        strcopy(s->che_pai,che_pai);
        strcopy(s->che_xing,che_xing);
        s->number=number;
        s->seat=seat;
        s->day_price=day_price;
        s->month_price=month_price;
        s->rent=rent;
        s->next=NULL;
        r->next=s;
        r=s;
    }
    fclose(fp);
    return head1;
}
TT *file2()
{
    char name[20];
    char id[20];
    char license[20];
    char phone[15];
    char workplace[40];
    char address[40];
    FILE *fp;
    fp=fopen("client_message.txt","r");
    TT *head2,*s,*r;
    r=head2;
    while(fscanf("%s %s %s %s %s %s",name,id,license,phone,workplace,address))
    {
        s=Y;//分配动态存储空间。
        strcpy(s->name,name);
        strcpy(s->id,id);
        strcpy(s->license,license);
        strcpy(s->phone,phone);
        strcpy(s->workplace,workplace);
        strcpy(s->address,address);
        s->next=NULL;
        r->next=s;
        r=s;
    }
    fclose(fp);
    return head2;
}
EE *file3()
{
    char name[20];
    char id[20];//身份证。
    char id_car[20];//车辆编号。
    char che_pai[10];
    int number;//车的数量。
    char type[6];//日租或包月。
    int term;//租期。
    int start_day;
    float deposit;//押金。
    float money1;//应交租金。
    int end_day;
    float money2;//实收租金。
    FILE *fp;
    fp=fopen("record.txt","r");
    EE *head3,*r,*s;
    r=head3;
    while(fscanf("%s %s %s %s %d %s %d %d %f %f %d %f",name,id,id_car,che_pai,
        &number,type,&term,&start_day,&deposit,&money1,&end_day,&money2)==12)
    {
        s=Z;//开辟新节点。
        strcpy(s->name,name);
        strcpy(s->id,id);
        strcpy(s->id_car,id_car);
        strcpy(s->che_pai,che_pai);
        s->number=number;
        strcpy(s->type,type);
        s->term=term;
        s->start_day=start_day;
        s->deposit=deposit;
        s->money1=money1;
        s->end_day=end_day;
        s->money2=money2;
        s->next=NULL;
        r->next=s;
        r=s;
    }
    fclose(fp);
    return;
}
void file1_w(RR *head1)
{
    FILE *fp;
    fp=fopen("car_message.txt","w");
    if(fp==NULL)
    {
        printf("文件打开失败!\n");
        exit(1);
    }
    RR *s;
    s=head1;
    while(s->next!=NULL)
    {
        s=s->next;
        fprintf("%d\t%s\t%s\t%d\t%d\t%f\t%f\t%d\n",s->id,s->che_pai,s->che_xing,
                s->number,s->seat,s->day_price,s->month_price,s->rent);
    }
    fclose(fp);
}
void file2_w(TT *head2)
{
    FILE *fp;
    fp=fopen("client_message.txt","w");
    if(fp==NULL)
    {
        printf("文件打开失败！\n");
        exit(1);
    }
    TT *s;
    s=head2;
    while(s->next!=NULL)
    {
        s=s->next;
        fprintf("%s\t%s\t%s\t%s\t%s\t%s\n",s->name,s->id,s->license,s->phone,
                 s->workplace,s->address);
    }
    fclose(fp);
}
void menu1()
{
    printf("\n******汽车租赁管理系统******\n");
    printf("0.退出\n"
           "1.车辆信息管理\n"
           "2.租车客户信息管理\n"
           "3.租车业务管理\n");
}
void menu2()
{
    printf("1.创建车辆信息\n"
           "2.增加车辆信息\n"
           "3.删除车辆信息\n"
           "4.修改车辆信息\n"
           "5.车辆查询\n"
           "6.显示所所有车辆信息\n");
}
void menu2_1()
{
    printf("请选择需要修改的车辆信息：\n"
                   "1.车辆编号\n"
                   "2.车牌号\n"
                   "3.车型\n"
                   "4.数量\n"
                   "5.座位数\n"
                   "6.日租价格\n"
                   "7.月租价格\n"
                   "8.已出租数量\n");
}
void menu2_2()
{
    printf("请选择查询方式：\n"
           "1.根据车辆编号查询\n"
           "2.根据车牌号查询\n"
           "3.根据车型查询\n"
           "4.根据座位数查询\n"
           "5.多个条件组合查询\n");
}
void menu2_2_1()
{
    printf("请选择组合方式：\n"
           "a.两个条件组合\n"
           "b.三个条件组合\n"
           "c.四个条件组合\n");
}
void menu3()
{
    printf("1.创建客户信息\n"
           "2.增加客户信息\n"
           "3.修改客户信息\n"
           "4.删除客户信息\n"
           "5.租车客户查询\n"
           "6.显示所有客户信息\n");
}
void menu3_1()
{
    printf("请选择需要修改的客户信息：\n"
           "1.客户姓名\n"
           "2.身份证\n"
           "3.驾驶证\n"
           "4.联系方式\n"
           "5.单位名称\n"
           "6.地址\n");
}
void menu3_2()
{
    printf("请选择查询方式：\n"
           "1.根据姓名查询\n"
           "2.根据身份证查询\n"
           "3.根据驾驶证查询\n"
           "4.根据电话查询\n"
           "5.多个条件组合查询\n");
}
void menu4()
{
    printf("1.创建车辆出租记录文件\n"
           "2.进行车辆出租\n"
           "3.进行车辆归还\n"
           "4.车辆出租情况查询\n"
           "5.月租金收入\n"
           "6.月各个车型的出租数量\n");
}
int printf_(RR *s,int flag)
{
    printf("%d %s %s %d %d %f %f %d\n",s->id,s->che_pai,s->che_xing,
            s->number,s->seat,s->day_price,s->month_price,s->rent);
    flag++;
    return flag;
}
int printf_2(TT *s,int flag)
{
    printf("%s %s %s %s %s %s\n",s->name,s->id,s->license,s->phone,
                 s->workplace,s->address);
    flag++;;
    return flag;
}
void car_creat(RR *head1)
{
    FILE *fp;
    fp=fopen("car_message.txt","a");
    if(fp==NULL)
    {
        printf("文件打开失败！\n");
        exit(1);
    }
    RR *s,*r;
    r=head1;
    while(r->next!=NULL)
    {
        r=r->next;
    }
    int t;
    printf("创建车辆信息的总数为：");
    scanf("%d",&t);
    while(t--)
    {
        s=X;//分配动态存储空间。
        printf("请输入车辆编号：");
        scanf("%d",&s->id);
        printf("请输入车牌号：");
        scanf("%s",s->che_pai);
        printf("请输入车型：");
        scanf("%s",s->che_xing);
        printf("请输入数量：");
        scanf("%d",&s->number);
        printf("请输入座位数：");
        scanf("%d",&s->seat);
        printf("请输入日租价格：");
        scanf("%f",&s->day_price);
        printf("请输入包月价格：");
        scanf("%f",&s->month_price);
        printf("请输入已出租数量：");
        scanf("%d",&s->rent);
        s->next=NULL;
        r->next=s;
        r=s;
        fprintf("%d\t%s\t%s\t%d\t%d\t%f\t%f\t%d\n",s->id,s->che_pai,s->che_xing,
                s->number,s->seat,s->day_price,s->month_price,s->rent);
    }
    fclose(fp);
    return;
}
void client_creat(TT *head2)
{
    FILE *fp;
    fp=fopen("client_message.txt","a");
    if(fp==NULL)
    {
        printf("文件打开失败！\n");
        exit(1);
    }
    TT *s,*r;
    r=head2;
    while(r->next!=NULL)
    {
        r=r->next;
    }
    int t;
    printf("创建客户信息的总数为：");
    scanf("%d",&t);
    while(t--)
    {
        s=Y;//分配动态存储空间。
        printf("请输入客户姓名：");
        scanf("%s",s->name);
        printf("请输入身份证：");
        scanf("%s",s->id);
        printf("请输入驾驶证：");
        scanf("%s",s->license);
        printf("请输入联系电话：");
        scanf("%s",s->phone);
        printf("请输入单位名称：");
        scanf("%s",s->workplace);
        printf("请输入地址：");
        scanf("%s",s->address);
        s->next=NULL;
        r->next=s;
        r=s;
        fprintf("%s\t%s\t%s\t%s\t%s\t%s\n",s->name,s->id,s->license,s->phone,
                 s->workplace,s->address);
    }
    fclose(fp);
    return;
}
void car_add(RR *head1)
{
    FILE *fp;
    fp=fopen("car_message.txt","a");
    if(fp==NULL)
    {
        printf("文件打开失败！\n");
        exit(1);
    }
    RR *s,*r;
    r=head1;
    while(r->next!=NULL)
    {
        r=r->next;
    }
    int t;
    printf("增加车辆信息的总数为：");
    scanf("%d",&t);
    while(t--)
    {
        s=X;//分配动态存储空间。
        printf("请输入车辆编号：");
        scanf("%d",&s->id);
        printf("请输入车牌号：");
        scanf("%s",s->che_pai);
        printf("请输入车型：");
        scanf("%s",s->che_xing);
        printf("请输入数量：");
        scanf("%d",&s->number);
        printf("请输入座位数：");
        scanf("%d",&s->seat);
        printf("请输入日租价格：");
        scanf("%f",&s->day_price);
        printf("请输入包月价格：");
        scanf("%f",&s->month_price);
        printf("请输入已出租数量：");
        scanf("%d",&s->rent);
        s->next=NULL;
        r->next=s;
        r=s;
        fprintf("%d\t%s\t%s\t%d\t%d\t%f\t%f\t%d\n",s->id,s->che_pai,s->che_xing,
                s->number,s->seat,s->day_price,s->month_price,s->rent);
    }
    fclose(fp);
    return;
}
void client_add(TT *head2)
{
    FILE *fp;
    fp=fopen("client_message.txt","a");
    if(fp==NULL)
    {
        printf("文件打开失败！\n");
        exit(1);
    }
    TT *s,*r;
    r=head2;
    while(r->next!=NULL)
    {
        r=r->next;
    }
    int t;
    printf("创建客户信息的总数为：");
    scanf("%d",&t);
    while(t--)
    {
        s=Y;//分配动态存储空间。
        printf("请输入客户姓名：");
        scanf("%s",s->name);
        printf("请输入身份证：");
        scanf("%s",s->id);
        printf("请输入驾驶证：");
        scanf("%s",s->license);
        printf("请输入联系电话：");
        scanf("%s",s->phone);
        printf("请输入单位名称：");
        scanf("%s",s->workplace);
        printf("请输入地址：");
        scanf("%s",s->address);
        s->next=NULL;
        r->next=s;
        r=s;
        fprintf("%s\t%s\t%s\t%s\t%s\t%s\n",s->name,s->id,s->license,s->phone,
                 s->workplace,s->address);
    }
    fclose(fp);
    return;
}
void car_delete(RR *head1)
{
    int id;
    printf("请输入要删除的车辆编号：");
    scanf("%d",&id);
    RR *r,*s;
    while(1)
    {
        r=head1;
        int flag=0;
        while(r->next!=NULL)
        {
            s=r;
            r=r->next;
            if(r->id==id)
            {
                s->next=r->next;
                free(r);
                printf("删除成功！\n");
                flag=1;
                break;
            }
        }
        if(flag==0)
        printf("Not Found!\n");
        char a;
        printf("是否继续进行删除操作?(y/n):");
        scanf("%s",&a);
        if(a=='y')
        continue;
        if(a=='n')
        break;
    }
    file1_w(head1);
    return;
}
void client_delete(TT *head2)
{
    char name[20];
    printf("请输入要删除的客户姓名：");
    scanf("%s",name);
    TT *r,*s;
    while(1)
    {
        r=head2;
        int flag=0;
        while(r->next!=NULL)
        {
            s=r;
            r=r->next;
            if(strcmp(r->name,name)==0)
            {
                s->next=r->next;
                free(r);
                printf("删除成功！\n");
                flag=1;
                break;
            }
        }
        if(flag==0)
        printf("Not Found!\n");
        char a;
        printf("是否继续进行删除操作?(y/n):");
        scanf("%s",&a);
        if(a=='y')
        continue;
        if(a=='n')
        break;
    }
    file2_w(head2);
    return;
}
void car_modify(RR *head1)
{
    int id;
    RR *r,*s;
    while(1)
    {
        printf("请输入要进行修改的车辆编号：");
        scanf("%d",&id);
        r=head1;
        int flag=0;
        while(r->next!=NULL)
        {
            r=r->next;
            if(r->id==id)
            {
            menu2_1();
            int t;
            scanf("%d",&t);
            switch(t)
            {
                case 1:
                printf("请输入车辆编号：");
                scanf("%d",&r->id);
                break;
                case 2:
                printf("请输入车牌号：");
                scanf("%s",r->che_pai);
                break;
                case 3:
                printf("请输入车型：");
                scanf("%s",r->che_xing);
                break;
                case 4:
                printf("请输入数量：");
                scanf("%d",&r->number);
                break;
                case 5:
                printf("请输入座位数：");
                scanf("%d",&r->seat);
                break;
                case 6:
                printf("请输入日租价格：");
                scanf("%f",&r->day_price);
                break;
                case 7:
                printf("请输入月租价格：");
                scanf("%f",&r->month_price);
                break;
                case 8:
                printf("请输入已出租数量：");
                scanf("%d",r->rent);
                break;
                default:printf("输入错误！拜拜。\n");
            }
            }
            file1_w(head1);
            printf("······修改成功！\n");
            break;
        }
        if(flag==0)
        printf("Not Found!\n");
        char a;
        printf("是否继续进行修改操作?(y/n):");
        scanf("%s",&a);
        if(a=='y')
        continue;
        if(a=='n')
        break;
    }
    return;
}
void client_modify(TT *head2)
{
    char name[20];
    TT *r,*s;
    while(1)
    {
        printf("请输入要进行修改的客户姓名：");
        scanf("%s",name);
        r=head2;
        int flag=0;
        while(r->next!=NULL)
        {
            r=r->next;
            if(strcmp(r->name,name)==0)
            {
            menu3_1();
            int t;
            scanf("%d",&t);
            switch(t)
            {
                case 1:
                printf("请输入客户姓名：");
                scanf("%s",r->name);
                break;
                case 2:
                printf("请输入身份证：");
                scanf("%s",r->id);
                break;
                case 3:
                printf("请输入驾驶证：");
                scanf("%s",r->license);
                break;
                case 4:
                printf("请输入联系方式：");
                scanf("%s",r->phone);
                break;
                case 5:
                printf("请输入单位名称：");
                scanf("%s",r->workplace);
                break;
                case 6:
                printf("请输入地址：");
                scanf("%s",r->address);
                break;
                default:printf("输入错误！拜拜。\n");
            }
            }
            file2_w(head2);
            printf("······修改成功！\n");
            break;
        }
        if(flag==0)
        printf("Not Found!\n");
        char a;
        printf("是否继续进行修改操作?(y/n):");
        scanf("%s",&a);
        if(a=='y')
        continue;
        if(a=='n')
        break;
    }
    return;
}
void car_query(RR *head1)
{
    menu2_2();
    int t;
    scanf("%d",&t);
    switch(t)
    {
        case 1:car_query1(head1);break;
        case 2:car_query2(head1);break;
        case 3:car_query3(head1);break;
        case 4:car_query4(head1);break;
        case 5:car_query5(head1);break;
        default:printf("输入错误！拜拜。\n");
    }
    return;
}
void client_query(TT *head2)
{
    menu3_2();
    int t;
    scanf("%d",&t);
    switch(t)
    {
        case 1:client_query1(head2);break;
        case 2:client_query2(head2);break;
        case 3:client_query3(head2);break;
        case 4:client_query4(head2);break;
        case 5:client_query5(head2);break;
        default:printf("输入错误！拜拜。\n");
    }
    return;
}
void car_query1(RR *head1)
{
    int id;
    int flag=0;
    printf("请输入车辆编号：");
    scanf("%d",&id);
    RR *s;
    s=head1;
    while(s->next!=NULL)
    {
        s=s->next;
        if(s->id==id)
        {
            flag=printf_(s,flag);
        }
    }
    if(flag==0)
    printf("Not Found!\n");
    return;
}
void client_query1(TT *head2)
{
    char name[20];
    int flag=0;
    printf("请输入客户姓名：");
    scanf("%s",name);
    TT *s;
    s=head2;
    while(s->next!=NULL)
    {
        s=s->next;
        if(strcmp(s->name,name)==0)
        {
            flag=printf_2(s,flag);
        }
    }
    if(flag==0)
    printf("Not Found!\n");
    return;
}
void car_query2(RR *head1)
{
    char che_pai[10];
    int flag=0;
    printf("请输入车牌号：");
    scanf("%s",che_pai);
    RR *s;
    s=head1;
    while(s->next!=NULL)
    {
        s=s->next;
        if(strcmp(s->che_pai,che_pai)==0)
        {
            flag=printf_(s,flag);
        }
    }
    if(flag==0)
    printf("Not Found!\n");
    return;
}
void client_query2(TT *head2)
{
    char id[20];
    int flag=0;
    printf("请输入身份证：");
    scanf("%s",id);
    TT *s;
    s=head2;
    while(s->next!=NULL)
    {
        s=s->next;
        if(strcmp(s->id,id)==0)
        {
            flag=printf_2(s,flag);
        }
    }
    if(flag==0)
    printf("Not Found!\n");
    return;
}
void car_query3(RR *head1)
{
    char che_xing[40];
    int flag=0;
    printf("请输入车型：");
    scanf("%s",che_xing);
    RR *s;
    s=head1;
    while(s->next!=NULL)
    {
        s=s->next;
        if(strcmp(s->che_xing,che_xing)==0)
        {
            flag=printf_(s,flag);
        }
    }
    if(flag==0)
    printf("Not Found!\n");
    return;
}
void client_query3(TT *head2)
{
    char license[20];
    int flag=0;
    printf("请输入驾驶证：");
    scanf("%s",license);
    TT *s;
    s=head2;
    while(s->next!=NULL)
    {
        s=s->next;
        if(strcmp(s->license,license)==0)
        {
            flag=printf_2(s,flag);
        }
    }
    if(flag==0)
    printf("Not Found!\n");
    return;
}
void car_query4(RR *head1)
{
    int seat;
    int flag=0;
    printf("请输入车辆编号：");
    scanf("%d",&seat);
    RR *s;
    s=head1;
    while(s->next!=NULL)
    {
        s=s->next;
        if(s->seat==seat)
        {
            flag=printf_(s,flag);
        }
    }
    if(flag==0)
    printf("Not Found!\n");
    return;
}
void client_query4(TT *head2)
{
    char phone[15];
    int flag=0;
    printf("请输入联系电话：");
    scanf("%s",phone);
    TT *s;
    s=head2;
    while(s->next!=NULL)
    {
        s=s->next;
        if(strcmp(s->phone,phone)==0)
        {
            flag=printf_2(s,flag);
        }
    }
    if(flag==0)
    printf("Not Found!\n");
    return;
}
void car_query5(RR *head1)
{   
    menu2_2_1();
    char x;
    int id;
    char che_pai[10];
    char che_xing[40];
    int seat;
    int flag=0;
    RR *s;
    s=head1;
    scanf("%s",&x);
    switch(x)
    {
        case 'a':
        {
            int m,n;
            printf("请顺序输入:__+__  (例: 1+2。加号也要写。)\n");
            scanf("%d+%d",&m,&n);
            printf("请依次输入信息：");
            if(m==1&&n==2)
            {
                scanf("%d %s",&id,che_pai);
                while(s->next!=NULL)
                {
                    s=s->next;
                    if(s->id==id && strcmp(s->che_pai,che_pai)==0)
                    {
                        printf_(s,flag);
                        flag++;
                    }
                }
            }
            else if(m==1&&n==3)
            {
                scanf("%d %s",&id,che_xing);
                while(s->next!=NULL)
                {
                    s=s->next;
                    if(s->id==id && strcmp(s->che_xing,che_xing)==0)
                    {
                        flag=printf_(s,flag);
                    }
                }
            }
            else if(m==1&&n==4)
            {
                scanf("%d %d",&id,&seat);
                while(s->next!=NULL)
                {
                    s=s->next;
                    if(s->id==id && s->seat==seat)
                    {
                        flag=printf_(s,flag);
                    }
                }
            }
            else if(m==2&&n==3)
            {
                scanf("%s %s",che_pai,che_xing);
                while(s->next!=NULL)
                {
                    s=s->next;
                    if(strcmp(s->che_pai,che_pai)==0 && strcmp(s->che_xing,che_xing)==0)
                    {
                        flag=printf_(s,flag);
                    }
                }
            }
            else if(m==2&&n==4)
            {
                scanf("%s %d",che_pai,&seat);
                while(s->next!=NULL)
                {
                    s=s->next;
                    if(strcmp(s->che_pai,che_pai)==0 && s->seat==seat)
                    {
                        flag=printf_(s,flag);
                    }
                }
            }
            else if(m==3&&n==4)
            {
                scanf("%d %s",che_xing,&seat);
                while(s->next!=NULL)
                {
                    s=s->next;
                    if(strcmp(s->che_xing,che_xing)==0 && s->seat==seat)
                    {
                        flag=printf_(s,flag);
                    }
                }
            }
            else
            {
                printf("输入错误！拜拜。\n");
                return;
            }
            if(flag==0)
            printf("Not Found!\n");
            break;
        }
        case 'b':
        {
            int m,n,p;
            printf("请顺序输入:__+__+__   (例: 1+2+3。加号也要写。)\n");
            scanf("%d+%d+%d",&m,&n,&p);
            printf("请依次输入信息：\n");
            if(m==1&&n==2&&p==3)
            {
                scanf("%d %s %s",&id,che_pai,che_xing);
                while(s->next!=NULL)
                {
                    s=s->next;
                    if(s->id==id && strcmp(s->che_pai,che_pai)==0 &&
                    strcmp(s->che_xing,che_xing)==0)
                    {
                        flag=printf_(s,flag);
                    }
                }
            }
            else if(m==1&&n==2&&p==4)
            {
                scanf("%d %s %d",&id,che_pai,&seat);
                while(s->next!=NULL)
                {
                    s=s->next;
                    if(s->id==id && strcmp(s->che_pai,che_pai)==0 && s->seat==seat)
                    {
                        flag=printf_(s,flag);
                    }
                }
            }
            else if(m==2&&n==3&&p==4)
            {
                scanf("%s %s %d",che_pai,che_xing,&seat);
                while(s->next!=NULL)
                {
                    s=s->next;
                    if(strcmp(s->che_pai,che_pai)==0 && strcmp(s->che_xing,che_xing)==0 && s->seat==seat)
                    {
                        flag=printf_(s,flag);
                    }
                }
            }
            else
            {
                printf("输入错误！拜拜。\n");
                return;
            }
            if(flag==0)
            printf("Not Found!\n");
            break;
        }
        case 'c':
        {
            printf("请依次输入信息：\n");
            scanf("%d %s %s %d",&id,che_pai,che_xing,&seat);
            while(s->next!=NULL)
            {
                s=s->next;
                if(s->id==id && strcmp(s->che_pai,che_pai)==0 &&
                   strcmp(s->che_xing,che_xing)==0 && s->seat==seat)
                {
                    flag=printf_(s,flag);
                }
            }
            if(flag==0)
            printf("Not Found!\n");
            break;
        }
        default:printf("输入错误！拜拜。\n");
    }
    return;
}
void client_query5(TT *head2)
{   
    menu2_2_1();
    char x;
    char name[20];
    char id[20];
    char license[20];
    char phone[15];
    int flag=0;
    TT *s;
    s=head2;
    scanf("%s",&x);
    switch(x)
    {
        case 'a':
        {
            int m,n;
            printf("请顺序输入:__+__  (例: 1+2。加号也要写。)\n");
            scanf("%d+%d",&m,&n);
            printf("请依次输入信息：");
            if(m==1&&n==2)
            {
                scanf("%s %s",name,id);
                while(s->next!=NULL)
                {
                    s=s->next;
                    if(strcmp(s->name,name)==0 && strcmp(s->id,id)==0)
                    {
                        flag=printf_2(s,flag);
                    }
                }
            }
            else if(m==1&&n==3)
            {
                scanf("%s %s",name,license);
                while(s->next!=NULL)
                {
                    s=s->next;
                    if(strcmp(s->name,name)==0 && strcmp(s->license,license)==0)
                    {
                        flag=printf_(s,flag);
                    }
                }
            }
            else if(m==1&&n==4)
            {
                scanf("%s %s",name,phone);
                while(s->next!=NULL)
                {
                    s=s->next;
                    if(strcmp(s->name,name)==0 && strcmp(s->phone,phone)==0)
                    {
                        flag=printf_(s,flag);
                    }
                }
            }
            else if(m==2&&n==3)
            {
                scanf("%s %s",id,license);
                while(s->next!=NULL)
                {
                    s=s->next;
                    if(strcmp(s->id,id)==0 && strcmp(s->license,license)==0)
                    {
                        flag=printf_(s,flag);
                    }
                }
            }
            else if(m==2&&n==4)
            {
                scanf("%s %s",id,phone);
                while(s->next!=NULL)
                {
                    s=s->next;
                    if(strcmp(s->id,id)==0 && strcmp(s->phone,phone)==0)
                    {
                        flag=printf_(s,flag);
                    }
                }
            }
            else if(m==3&&n==4)
            {
                scanf("%s %s",license,phone);
                while(s->next!=NULL)
                {
                    s=s->next;
                    if(strcmp(s->license,license)==0 && strcmp(s->phone,phone)==0)
                    {
                        flag=printf_(s,flag);
                    }
                }
            }
            else
            {
                printf("输入错误！拜拜。\n");
                return;
            }
            if(flag==0)
            printf("Not Found!\n");
            break;
        }
        case 'b':
        {
            int m,n,p;
            printf("请顺序输入:__+__+__   (例: 1+2+3。加号也要写。)\n");
            scanf("%d+%d+%d",&m,&n,&p);
            printf("请依次输入信息：\n");
            if(m==1&&n==2&&p==3)
            {
                scanf("%s %s %s",name,id,license);
                while(s->next!=NULL)
                {
                    s=s->next;
                    if(strcmp(s->name,name)==0 && strcmp(s->id,id)==0 &&
                    strcmp(s->license,license)==0)
                    {
                        flag=printf_(s,flag);
                    }
                }
            }
            else if(m==1&&n==2&&p==4)
            {
                scanf("%s %s %s",name,id,phone);
                while(s->next!=NULL)
                {
                    s=s->next;
                    if(strcmp(s->name,name)==0 && strcmp(s->id,id)==0 &&
                    strcmp(s->phone,phone)==0)
                    {
                        flag=printf_(s,flag);
                    }
                }
            }
            else if(m==2&&n==3&&p==4)
            {
                scanf("%s %s %s",id,license,phone);
                while(s->next!=NULL)
                {
                    s=s->next;
                    if(strcmp(s->id,id)==0 && strcmp(s->license,license)==0 &&
                    strcmp(s->phone,phone)==0)
                    {
                        flag=printf_(s,flag);
                    }
                }
            }
            else
            {
                printf("输入错误！拜拜。\n");
                return;
            }
            if(flag==0)
            printf("Not Found!\n");
            break;
        }
        case 'c':
        {
            printf("请依次输入信息：\n");
            scanf("%s %s %s %s",name,id,license,phone);
            while(s->next!=NULL)
            {
                s=s->next;
                if(strcmp(s->name,name) && strcmp(s->id,id)==0 &&
                   strcmp(s->license,license)==0 && strcmp(s->phone,phone))
                {
                    flag=printf_(s,flag);
                }
            }
            if(flag==0)
            printf("Not Found!\n");
            break;
        }
        default:printf("输入错误！拜拜。\n");
    }
    return;
}
void car_display(RR *head1)
{
    RR *s;
    s=head1;
    while(s->next!=NULL)
    {
        printf("%d %s %s %d %d %f %f %d\n",s->id,s->che_pai,s->che_xing,
                s->number,s->seat,s->day_price,s->month_price,s->rent);
    }
    return;
}
void client_display(TT *head2)
{
    TT *s;
    s=head2;
    while(s->next!=NULL)
    {
        printf("%s %s %s %s %s %s\n",s->name,s->id,s->license,s->phone,
                 s->workplace,s->address);
    }
    return;
}
void trade1(EE *head3)
{
    /*
     FILE *fp;
    fp=fopen("car_message.txt","a");
    if(fp==NULL)
    {
        printf("文件打开失败！\n");
        exit(1);
    }
    RR *s,*r;
    r=head1;
    while(r->next!=NULL)
    {
        r=r->next;
    }
    int t;
    printf("创建车辆信息的总数为：");
    scanf("%d",&t);
    while(t--)
    {
        s=X;//分配动态存储空间。
        printf("请输入车辆编号：");
        scanf("%d",&s->id);
        printf("请输入车牌号：");
        scanf("%s",s->che_pai);
        printf("请输入车型：");
        scanf("%s",s->che_xing);
        printf("请输入数量：");
        scanf("%d",&s->number);
        printf("请输入座位数：");
        scanf("%d",&s->seat);
        printf("请输入日租价格：");
        scanf("%f",&s->day_price);
        printf("请输入包月价格：");
        scanf("%f",&s->month_price);
        printf("请输入已出租数量：");
        scanf("%d",&s->rent);
        s->next=NULL;
        r->next=s;
        r=s;
        fprintf("%d\t%s\t%s\t%d\t%d\t%f\t%f\t%d\n",s->id,s->che_pai,s->che_xing,
                s->number,s->seat,s->day_price,s->month_price,s->rent);
    }
    fclose(fp);
    return;*/
    FILE *fp;
    fp=fopen("record.txt","a");
    if(fp==NULL)
    {
        printf("文件打开失败！\n");
        exit(1);
    }
    

}
//主函数
int main(){
    printf("网安243朱含韵 202401050887\n");
    RR *head1;
    TT *head2;
    EE *head3;
    head1=file1();
    head2=file2();
    head3=file3();
    menu1();
    int x,n;
    printf("请选择要管理的信息：");
    while(scanf("%d",&x)==1)
    {
        if(x==0)
        {
            return 0;
        }
        else if(x==1)
        {
            menu2();
            scanf("%d",&n);
            switch(n)
            {
                case 1:car_creat(head1);break;
                case 2:car_add(head1);break;
                case 3:car_delete(head1);break;
                case 4:car_modify(head1);break;
                case 5:car_query(head1);break;
                case 6:car_display(head1);break;
                default:printf("输入错误！拜拜。\n");
            }
        }
        else if(x==2)
        {
            menu3();
            scanf("%d",&n);
            switch(n)
            {
                case 1:client_creat(head2);break;
                case 2:client_add(head2);break;
                case 3:client_modify(head2);break;
                case 4:client_delete(head2);break;
                case 5:client_query(head2);break;
                case 6:client_display(head2);break;
                default:printf("输入错误！拜拜。\n");
            }
        }
        else if(x==3)
        {
            /*
            printf("1.进行车辆出租\n"
           "2.进行车辆归还\n"
           "3.车辆出租情况查询\n"
           "4.月租金收入\n"
           "5.月各个车型的出租数量\n");*/
            menu4();
            scanf("%d",&n);
            switch(n)
            {
                case 1:trade1(head3);break;
                case 2:trade2();break;
                case 3:trade3();break;
                case 4:trade4();break;
                case 5:trade5();break;
                case 6:trade6();break;
                default:printf("输入错误！拜拜。\n");
            }
        }
        else
        printf("输入错误！请重新输入。\n");
        void menu1();
        printf("请选择要管理的信息：");
    }
}

