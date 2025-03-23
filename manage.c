#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define X (RR*)malloc(sizeof(RR))
#define Y (TT*)malloc(sizeof(TT))
#define Z (EE*)malloc(sizeof(EE))

//定义结构体
typedef struct car
{
    int id;//车辆编号
    char che_pai[10];//车牌号
    char che_xing[40];//车型
    int number;//车的数量
    int seat;//座位数
    float day_price;//日租价格
    float month_price;//月租价格
    int rent;//已出租数量
    struct car *next;
}RR;
typedef struct client
{
    char name[20];//客户姓名
    char id[20];//身份证
    char license[20];//驾驶证
    char phone[15];//电话号码
    char workplace[40];//单位地址
    char address[40];//住址
    struct client *next;
}TT;
typedef struct trade
{
    char name[20];//客户姓名
    char id[20];//身份证
    int id_car;//车辆编号
    char che_pai[10];//车牌号
    int number;//车的数量
    char type[6];//日租或包月
    int term;//租期
    int start_day;//出租时间
    float deposit;//押金
    float money1;//应交租金
    int end_day;//归还时间
    float money2;//实收租金
    struct trade *next;
}EE;
typedef struct temp
{
        char che_xing[40];
        int number;
        struct temp *next;
}PP;

//函数列表
RR *file1();
TT *file2();
EE *file3();
void choice(RR *head1,TT *head2,EE *head3);
void file1_w(RR *head1);
void file2_w(TT *head2);
void menu1();
void menu2();
void menu2_1();
void menu2_2();
void menu2_2_1();
void menu3();
void menu3_1();
void menu3_2();
void menu4();
void menu4_1();

int printf_(RR *s,int flag);
RR *car_creat();
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
TT *client_creat();
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

void printf_3(EE *r);
void trade_on(EE *head3,TT *head2,RR *head1);
void trade_off(EE *head3,RR *head1);
void trade_inquery(EE *head3);
void trade_inquery1(EE *head3);
void trade_inquery2(EE *head3);
void trade_inquery3(EE *head3);
void trade_money(EE *head3);
void trade_number(EE *head3,RR *head1);
void func(RR *head1,RR *s,EE *r,PP *q,PP *head4);

//主函数
int main(){
    printf("网安243朱含韵 202401050887\n");
    printf("(温馨提示：新手开店，请先选 1 -> 1 创建车辆信息。\n");
    printf("           没有车，你什么也干不了!  车辆编号唯一！)\n");
    //构建新链表，导入之前的文件内容。
    RR *head1;
    TT *head2;
    EE *head3;
    head1=file1();
    head2=file2();
    head3=file3();
    menu1();//显示主菜单
    choice(head1,head2,head3);//选择函数
}

//函数定义
RR *file1()//导入车辆信息文件
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
    head1=X;
    head1->next=NULL;
    r=head1;
    while(fscanf(fp,"%d %s %s %d %d %f %f %d",&id,che_pai,che_xing,&number,
                  &seat,&day_price,&month_price,&rent)==8)
    {
        s=X;//分配动态存储空间。
        s->id=id;
        strcpy(s->che_pai,che_pai);
        strcpy(s->che_xing,che_xing);
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

TT *file2()//导入客户信息文件
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
    head2=Y;
    head2->next=NULL;
    r=head2;
    while(fscanf(fp,"%s %s %s %s %s %s",name,id,license,phone,workplace,address)==6)
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

EE *file3()//导入业务信息文件
{
    char name[20];
    char id[20];
    int id_car;
    char che_pai[10];
    int number;
    char type[6];
    int term;
    int start_day;
    float deposit;
    float money1;
    int end_day;
    float money2;
    FILE *fp;
    fp=fopen("record.txt","r");
    EE *head3,*r,*s;
    head3=Z;
    head3->next=NULL;
    r=head3;
    while(fscanf(fp,"%s %s %d %s %d %s %d %d %f %f %d %f",name,id,&id_car,che_pai,
        &number,type,&term,&start_day,&deposit,&money1,&end_day,&money2)==12)
    {
        s=Z;//开辟新节点。
        strcpy(s->name,name);
        strcpy(s->id,id);
        s->id_car=id_car;
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
    return head3;
}

void choice(RR *head1,TT *head2,EE *head3)//选择函数
{
    int x,n;
    printf("请选择要管理的信息：");
    while(scanf("%d",&x)==1)
    {
        if(x==0)
        {
            return;
        }
        else if(x==1)
        {
            menu2();
            scanf("%d",&n);
            switch(n)
            {
                case 1:head1=car_creat();break;
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
                case 1:head2=client_creat();break;
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
            menu4();
            scanf("%d",&n);
            switch(n)
            {
                case 1:trade_on(head3,head2,head1);break;
                case 2:trade_off(head3,head1);break;
                case 3:trade_inquery(head3);break;
                case 4:trade_money(head3);break;
                case 5:trade_number(head3,head1);break;
                default:printf("输入错误！拜拜。\n");
            }
        }
        else
        printf("输入错误！拜拜。\n");
        menu1();
        printf("请选择要管理的信息：");
    }
}

void file1_w(RR *head1)//函数：用来重写车辆信息文件。
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
        fprintf(fp,"%d\t%s\t%s\t%d\t%d\t%.2f\t%.2f\t%d\n",s->id,s->che_pai,s->che_xing,
                s->number,s->seat,s->day_price,s->month_price,s->rent);
    }
    fclose(fp);
}

void file2_w(TT *head2)//函数：用来重写客户信息文件。
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
        fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\n",s->name,s->id,s->license,s->phone,
                 s->workplace,s->address);
    }
    fclose(fp);
}

void menu1()
{
    printf("\n******汽车租赁管理系统******\n");
    printf("1.车辆信息管理\n"
           "2.租车客户信息管理\n"
           "3.租车业务管理\n"
           "0.退出\n");
}

void menu2()
{
    printf("\n-----车辆信息管理-----\n"
           "1.创建车辆信息\n"
           "2.增加车辆信息\n"
           "3.删除车辆信息\n"
           "4.修改车辆信息\n"
           "5.车辆查询\n"
           "6.显示所有车辆信息\n");
    printf("请选择需要进行的操作：");
}

void menu2_1()
{
    printf("\n1.车辆编号\n"
           "2.车牌号\n"
           "3.车型\n"
           "4.数量\n"
           "5.座位数\n"
           "6.日租价格\n"
           "7.月租价格\n"
           "8.已出租数量\n");
    printf("请选择需要修改的车辆信息：");
}

void menu2_2()
{
    printf("\n1.根据车辆编号查询\n"
           "2.根据车牌号查询\n"
           "3.根据车型查询\n"
           "4.根据座位数查询\n"
           "5.多个条件组合查询\n"
           "请选择查询方式：");
}

void menu2_2_1()
{
    printf("\na.两个条件组合\n"
           "b.三个条件组合\n"
           "c.四个条件组合\n"
           "请选择组合方式：");
}

void menu3()
{
    printf("\n-----客户信息管理-----\n"
           "1.创建客户信息\n"
           "2.增加客户信息\n"
           "3.修改客户信息\n"
           "4.删除客户信息\n"
           "5.租车客户查询\n"
           "6.显示所有客户信息\n");
    printf("请选择需要进行的操作：");
}

void menu3_1()
{
    printf("\n1.客户姓名\n"
           "2.身份证\n"
           "3.驾驶证\n"
           "4.电话\n"
           "5.工作单位\n"
           "6.住址\n"
           "请选择需要修改的客户信息：");
}

void menu3_2()
{
    printf("\n1.根据姓名查询\n"
           "2.根据身份证查询\n"
           "3.根据驾驶证查询\n"
           "4.根据电话查询\n"
           "5.多个条件组合查询\n"
           "请选择查询方式：");
}

void menu4()
{
    printf("\n-----业务管理-----\n"
           "1.进行车辆出租\n"
           "2.进行车辆归还\n"
           "3.车辆出租情况查询\n"
           "4.查看月租金收入\n"
           "5.查看月各个车型的出租数量\n");
    printf("请输入需要进行的操作：");
}

void menu4_1()
{
    printf("\n1.按客户姓名查询\n"
           "2.按车牌号查询\n"
           "3.按出租时间查询\n"
           "请选择查询方式：");
}

int printf_(RR *s,int flag)//函数：用来显示车辆信息的查询结果。
{
    printf("车辆编号   车牌号        车型         数量     座位数    日租价格    月租价格     已出租数量\n");
    printf("%-9d  %-14s%-13s%-9d%-8d  %-11.2f %-13.2f%-8d\n",s->id,s->che_pai,s->che_xing,
            s->number,s->seat,s->day_price,s->month_price,s->rent);
    flag++;
    return flag;
}

int printf_2(TT *s,int flag)//函数：用来显示客户信息的查询结果。
{
    printf("姓名       身份证             驾驶证         电话         工作单位       住址\n");
    printf("%-11s%-19s%-15s%-13s%-15s%-14s\n",s->name,s->id,s->license,s->phone,
                 s->workplace,s->address);
    flag++;;
    return flag;
}

void printf_3(EE *r)//函数：显示业务信息的结果。
{
    //画个表，更好看些。
    printf("+----------------------------+\n");
    printf("| 姓名：%-11s          |\n",r->name);
    printf("| 身份证：%-19s|\n",r->id);
    printf("| 车辆编号：%-9d        |\n",r->id_car);
    printf("| 车牌号：%-14s     |\n",r->che_pai);
    printf("| 数量：%-9d            |\n",r->number);
    printf("| 类型：%-6s               |\n",r->type);
    printf("| 租期：%-13d        |\n",r->term);
    printf("| 押金：%-13.2f        |\n",r->deposit);
    printf("| 应交租金：%-17.2f|\n",r->money1);
    printf("| 实收租金：%-17.2f|\n",r->money2);
    printf("| 出租时间：%-17d|\n",r->start_day);
    printf("| 归还时间：%-17d|\n",r->end_day);
    printf("+----------------------------+\n");
}

RR *car_creat()//创建车辆信息文件。
{
    FILE *fp;
    fp=fopen("car_message.txt","w");
    if(fp==NULL)
    {
        printf("文件打开失败！\n");
        exit(1);
    }
    RR *head1,*s,*r;
    head1=X;
    r=head1;
    int t;
    printf("创建车辆信息的总数为：");//控制循环次数。
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        s=X;//分配动态存储空间。
        printf(" #车辆%d\n",i);
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
        s->next=NULL;//最后一个节点的指针域确保储存为NULL。
        r->next=s;//链表连接。
        r=s;
        fprintf(fp,"%d\t%s\t%s\t%d\t%d\t%.2f\t%.2f\t%d\n",s->id,s->che_pai,s->che_xing,
                s->number,s->seat,s->day_price,s->month_price,s->rent);//顺便将结果添加到文件中。
    }
    printf("······添加已完成！\n");
    fclose(fp);
    return head1;//返回头节点的地址。
}

TT *client_creat()//创建客户信息文件。
{
    FILE *fp;
    fp=fopen("client_message.txt","w");
    if(fp==NULL)
    {
        printf("文件打开失败！\n");
        exit(1);
    }
    TT *head2,*s,*r;
    head2=Y;
    r=head2;
    int t;
    printf("创建客户信息的总数为：");//控制循环次数。
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        s=Y;//分配动态存储空间。
        printf(" #客户%d\n",i);
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
        r->next=s;//链表连接。
        r=s;
        fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\n",s->name,s->id,s->license,s->phone,
                 s->workplace,s->address);//顺便将结果添加到文件中。
    }
    printf("······添加已完成！\n");
    fclose(fp);
    return head2;
}

//下面两个添加函数与上面的创建函数的思路，基本相同。
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
    for(int i=1;i<=t;i++)
    {
        s=X;//分配动态存储空间。
        printf(" #车辆%d\n",i);
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
        r->next=s;//链表连接。
        r=s;
        fprintf(fp,"%d\t%s\t%s\t%d\t%d\t%.2f\t%.2f\t%d\n",s->id,s->che_pai,s->che_xing,
                s->number,s->seat,s->day_price,s->month_price,s->rent);
    }
    printf("······添加已完成！\n");
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
    printf("增加客户信息的总数为：");
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        s=Y;//分配动态存储空间。
        printf(" #客户%d\n",i);
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
        fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\n",s->name,s->id,s->license,s->phone,
                 s->workplace,s->address);
    }
    printf("······添加已完成！\n");
    fclose(fp);
    return;
}

void car_delete(RR *head1)
{
    int id;
    RR *r,*s;
    while(1)//条件为真，循环持续进行。
    {
        printf("请输入要删除的车辆编号：");
        scanf("%d",&id);
        r=head1;
        int flag=0;
        while(r->next!=NULL)
        {
            s=r;
            r=r->next;
            if(r->id==id)
            {
                s->next=r->next;
                free(r);//“删除”后，释放节点。
                file1_w(head1);//重写文件内容。
                printf("······删除成功！\n");
                flag=1;
                break;
            }
        }
        if(flag==0)
        printf("Not Found!\n");
        char a;
        printf("请问是否继续进行删除操作?(y/n):");
        scanf("%s",&a);
        if(a=='y')
        continue;//循环继续。
        if(a=='n')
        break;//循环结束。
    }
    return;
}

void client_delete(TT *head2)
{
    char name[20];
    TT *r,*s;
    while(1)
    {
        printf("请输入要删除的客户姓名：");
        scanf("%s",name);
        r=head2;
        int flag=0;
        while(r->next!=NULL)
        {
            s=r;
            r=r->next;
            if(strcmp(r->name,name)==0)
            {
                s->next=r->next;
                free(r);//“删除”后，释放节点。
                file2_w(head2);//重写文件内容。
                printf("······删除成功！\n");
                flag=1;
                break;
            }
        }
        if(flag==0)
        printf("Not Found!\n");
        char a;
        printf("请问是否继续进行删除操作?(y/n):");
        scanf("%s",&a);
        if(a=='y')
        continue;//循环继续。
        if(a=='n')
        break;//循环结束。
    }
    return;
}

void car_modify(RR *head1)
{
    int id;
    RR *r;
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
            flag=1;
            menu2_1();//显示菜单。
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
                scanf("%d",&r->rent);
                break;
                default:printf("输入错误！拜拜。\n");
            }
            file1_w(head1);//重写文件。
            printf("······修改成功！\n");
            break;
            }
        }
        if(flag==0)
        printf("Not Found!\n");
        char a;
        printf("请问是否继续进行修改操作?(y/n):");
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
    TT *r;
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
            flag=1;
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
            file2_w(head2);//重写文件。
            printf("······修改成功！\n");
            break;
            }
        }
        if(flag==0)
        printf("Not Found!\n");
        char a;
        printf("请问是否继续进行修改操作?(y/n):");
        scanf("%s",&a);
        if(a=='y')
        continue;//循环继续。
        if(a=='n')
        break;//循环结束。
    }
    return;
}

void car_query(RR *head1)
{
    menu2_2();//显示菜单。
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
    menu3_2();//显示菜单。
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
            flag=printf_(s,flag);//函数：显示查询结果，同时返回一个非零值。
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
            flag=printf_2(s,flag);//函数：显示查询结果，同时返回一个非零值。
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
            flag=printf_(s,flag);//函数：显示查询结果，同时返回一个非零值。
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
            flag=printf_2(s,flag);//函数：显示查询结果，同时返回一个非零值。
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
            flag=printf_(s,flag);//函数：显示查询结果，同时返回一个非零值。
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
            flag=printf_2(s,flag);//函数：显示查询结果，同时返回一个非零值。
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
    printf("请输入座位数：");
    scanf("%d",&seat);
    RR *s;
    s=head1;
    while(s->next!=NULL)
    {
        s=s->next;
        if(s->seat==seat)
        {
            flag=printf_(s,flag);//函数：显示查询结果，同时返回一个非零值。
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
            flag=printf_2(s,flag);//函数：显示查询结果，同时返回一个非零值。
        }
    }
    if(flag==0)
    printf("Not Found!\n");
    return;
}

void car_query5(RR *head1)
{
    menu2_2_1();//显示菜单。
    char x;
    int id;
    char che_pai[10];
    char che_xing[40];
    int seat;
    int flag=0;
    RR *s;
    scanf("%s",&x);
    switch(x)
    {
        case 'a'://两个条件组合，难度最大。
        {
            s=head1;//每次操作，s指针都要从头开始。小bug：这条语句放在最前面，cb上运行有时会失效。
            int m,n;
            printf("\n请选择组合条件：\n"
                   "1.车辆编号。2.车牌号。3.车型。4.座位数。\n");
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
                        flag=printf_(s,flag);
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
                scanf("%s %d",che_xing,&seat);
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
        case 'b'://三个条件组合
        {
            s=head1;//s指针从头开始。
            int m,n,p;
            printf("\n请选择组合条件：\n"
                   "1.车辆编号。2.车牌号。3.车型。4.座位数。\n");
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
                        flag=printf_(s,flag);//函数：显示查询结果，同时返回一个非零值。
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
            else//输入错误的情况。
            {
                printf("输入错误！拜拜。\n");
                return;
            }
            if(flag==0)
            printf("Not Found!\n");
            break;
        }
        case 'c'://四个条件组合，最简单。
        {
            s=head1;
            printf("\n已选择全部组合条件：\n"
                   "1.车辆编号。2.车牌号。3.车型。4.座位数。\n");
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
    menu2_2_1();//显示菜单。
    char x;
    char name[20];
    char id[20];
    char license[20];
    char phone[15];
    int flag=0;
    TT *s;
    scanf("%s",&x);
    switch(x)
    {
        case 'a'://两个条件组合。
        {
            s=head2;
            int m,n;
            printf("\n请选择组合条件：\n"
                  "1.姓名。2.身份证。3.驾驶证。4.电话号码。\n");
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
                        flag=printf_2(s,flag);
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
                        flag=printf_2(s,flag);
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
                        flag=printf_2(s,flag);
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
                        flag=printf_2(s,flag);
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
                        flag=printf_2(s,flag);
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
        case 'b'://三个条件组合。
        {
            s=head2;
            int m,n,p;
            printf("\n请选择组合条件：\n"
                  "1.姓名。2.身份证。3.驾驶证。4.电话号码。\n");
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
                        flag=printf_2(s,flag);
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
                        flag=printf_2(s,flag);
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
                        flag=printf_2(s,flag);
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
        case 'c'://四个条件组合。
        {
            s=head2;
            printf("\n已选择全部组合条件：\n"
                  "1.姓名。2.身份证。3.驾驶证。4.电话号码。\n");
            printf("请依次输入信息：\n");
            scanf("%s %s %s %s",name,id,license,phone);
            while(s->next!=NULL)
            {
                s=s->next;
                if(strcmp(s->name,name)==0 && strcmp(s->id,id)==0 &&
                   strcmp(s->license,license)==0 && strcmp(s->phone,phone)==0)
                {
                    flag=printf_2(s,flag);
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

void car_display(RR *head1)//函数：显示所有结果。
{
    RR *s;
    s=head1;
        printf("+---------+--------------+-------------+---------+--------+-----------+-------------+----------+\n");
        printf("|车辆编号 |车牌号        |车型         |数量     |座位数  |日租价格   |月租价格     |已出租数量|\n");
        printf("+---------+--------------+-------------+---------+--------+-----------+-------------+----------+\n");
    while(s->next!=NULL)
    {
        s=s->next;
        printf("|%-9d|%-14s|%-13s|%-9d|%-8d|%-11.2f|%-13.2f|%-10d|\n",s->id,s->che_pai,s->che_xing,
                s->number,s->seat,s->day_price,s->month_price,s->rent);
    }
        printf("+---------+--------------+-------------+---------+--------+-----------+-------------+----------+\n");
    return;
}

void client_display(TT *head2)//函数：显示所有结果。
{
    TT *s;
    s=head2;
        printf("+-----------+-------------------+---------------+-------------+---------------+--------------+\n");
        printf("|姓名       |身份证             |驾驶证         |电话         |工作单位       |住址          |\n");
        printf("+-----------+-------------------+---------------+-------------+---------------+--------------+\n");
    while(s->next!=NULL)
    {
        s=s->next;
        printf("|%-11s|%-19s|%-15s|%-13s|%-15s|%-14s|\n",s->name,s->id,s->license,s->phone,
                 s->workplace,s->address);
    }
        printf("+-----------+-------------------+---------------+-------------+---------------+--------------+\n");
    return;
}

void trade_on(EE *head3,TT *head2,RR *head1)//函数：进行车辆出租。
{
    int n;
    int id_car;
    char che_pai[10];
    char che_xing[40];
    int number;
    float day_price;
    float month_price;
    int rent;
    char name[20];
    char id[20];
    char license[20];
    char phone[15];
    char workplace[40];
    char address[40];
    char type[6];
    int term;
    int start_day;
    float deposit;
    float money1;
    int end_day;
    float money2;
    printf("请输入车辆出租的总数：");//控制循环条件。
    scanf("%d",&n);
    printf("【注意：前面必须有这辆车，后面才能租给客户，严禁无中生有！！】\n");
    EE *r,*s,*m;
    r=head3;
    while(r->next!=NULL)
    {
        r=r->next;//尾插法，指针指向最后。
    }
    for(int i=1;i<=n;i++)
    {
        s=Z;//开辟新节点。
        printf(" #出租车辆%d\n",i);
        printf("第一步：请依次输入车辆编号、车牌号(注意与之前的数据一致)：\n");
        scanf("%d %s",&id_car,che_pai);
        printf("第二步：请依次输入客户姓名、身份证：\n");
        scanf("%s %s",name,id);
        printf("第三步：请依次输入租车类型(day/month)、租期(符合实际)、租车开始时间(年月日，例:20240102)、押金：\n");
        scanf("%s %d %d %f",type,&term,&start_day,&deposit);
        strcpy(s->name,name);
        strcpy(s->id,id);
        s->id_car=id_car;
        strcpy(s->che_pai,che_pai);
        //下面算一下number,我理解为客户总的租车数量。
        m=head3;
        int flag=0;
        while(m->next!=NULL)
        {
           m=m->next;
           if(strcmp(m->name,name)==0)//经判断为老客户，租车数量在原有基础上+1.
           {
               s->number=m->number+1;
               flag++;
           }
        }
        if(flag==0)
        {
            s->number=1;
        }
        strcpy(s->type,type);
        s->term=term;
        s->start_day=start_day;
        s->deposit=deposit;
        s->end_day=0;//归还时间初始化为0.
        s->money2=0;//实收租金初始化为0。
        //下面算应交租金。
        RR *p=head1;
        while(p->next!=NULL)
        {
            p=p->next;
            if(p->id==id_car)
            {
                day_price=p->day_price;//利用车辆链表，找到对应的日租、月租价格。
                month_price=p->month_price;
                p->rent=p->rent+1;//对应车辆已出租数量加上1。
                file1_w(head1);//修改车辆基本信息文件。
                break;
            }
        }
        if(strcmp(s->type,"day")==0)//判断是月租类型还是日租类型。
        {
            s->money1=day_price*term;
        }
        else if(strcmp(s->type,"month")==0)
        {
            s->money1=month_price*term;
        }
        s->next=NULL;
        r->next=s;
        r=s;
        //将业务记录写到文件中。
        FILE *fp;
        fp=fopen("record.txt","a");
        if(fp==NULL)
        {
            printf("文件打开失败！\n");
            exit(1);
        }
        fprintf(fp,"%s\t%s\t%d\t%s\t%d\t%s\t%d\t%d\t%.2f\t%.2f\t%d\t%.2f\n",r->name,r->id,r->id_car,r->che_pai,
                             r->number,r->type,r->term,r->start_day,r->deposit,r->money1,r->end_day,r->money2);
        fclose(fp);
        //下面判断是否为新客户。若是，将新客户信息添加到租车客户信息文件管理中。
        flag=0;
        TT *q=head2,*k;
        while(q->next!=NULL)
        {
            q=q->next;
            if(strcmp(q->name,name)==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("!!!检测到该用户为新客户，现追加基本信息。\n");
            printf("请依次输入客户电话、驾驶证、单位名称、地址：\n");
            scanf("%s %s %s %s",phone,license,workplace,address);
            FILE *fp;
            fp=fopen("client_message.txt","a");
            if(fp==NULL)
            {
                printf("文件打开失败！\n");
                exit(1);
            }
            fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\n",name,id,license,phone,workplace,address);
            fclose(fp);
            //为客户链表增加一个节点。
            k=Y;//开辟新节点。
            strcpy(k->name,name);
            strcpy(k->id,id);
            strcpy(k->license,license);
            strcpy(k->phone,phone);
            strcpy(k->workplace,workplace);
            strcpy(k->address,address);
            k->next=NULL;
            q->next=k;
            q=k;
        }
        printf("······输入完成！\n");
    }
}

void trade_off(EE *head3,RR *head1)//函数：进行车辆归还。
{
    char name[20];
    int id_car;
    int end_day;
    int start_day;
    int term;
    float day_price;
    float month_price;
    char type[6];
    float money1;
    float money2;
    float money0;
    printf("请依次输入客户姓名、车辆编号：\n");
    scanf("%s %d",name,&id_car);
    printf("请输入归还时间：(年月日,例:20240102)\n");
    scanf("%d",&end_day);
    //修改车辆
    RR *s;
    s=head1;
    while(s->next!=NULL)
    {
        s=s->next;
        if(s->id==id_car)
        {
            s->rent=s->rent-1;//车辆已出租数量-1。
            file1_w(head1);//修改车辆基本信息文件。
            day_price=s->day_price;
            month_price=s->month_price;
            break;
        }
    }
    EE *r;
    r=head3;
    while(r->next!=NULL)
    {
        r=r->next;
        if(r->id_car==id_car &&strcmp(r->name,name)==0)
        {
            term=r->term;
            start_day=r->start_day;
            strcpy(type,r->type);
            break;
        }
    }
        int day1;
        int day2;
        int month1;
        int month2;
        int year1;
        int year2;
        day1=start_day%100;
        day2=end_day%100;
        month1=start_day/100%100;
        month2=end_day/100%100;
        year1=start_day/10000;
        year2=end_day/10000;
        int time;
    //为节省计算，假定一个月为30天。
    if(strcmp(type,"day")==0)
    {
        if(year1!=year2)
        {
            time=(year2-year1-1)*360+(12-month1-1)*30+30-day1+(month2-1)*30+day2;
        }
        else if(year1==year2)
        {
            if(month1!=month2)
            {
                time=(month2-month1-1)*30+day2+30-day1;
            }
            else if(month1==month2)
            {
                time=day2-day1;
            }
        }
        money1=term*day_price;//计算应交租金。
        if(time<term)
        {
            money0=(term-time)*day_price;
            money2=money1-money0;
            printf("本次租车时长为：%d天。经判断,为提前归还。\n",time);
            printf("实收租金：%.2f 。其中应交租金：%.2f  退款金额：%.2f\n",money2,money1,money0);
        }
        else if(time>term)
        {
            money0=(time-term)*day_price;
            money2=money1+money0;
            printf("本次租车时长为：%d天。经判断,为过期归还。\n",time);
            printf("实收租金：%.2f 。其中应交租金：%.2f  补交金额：%.2f\n",money2,money1,money0);
        }
        else if(time==term)
        {
            money2=money1;
            printf("本次租车时长为：%d天。\n",time);
            printf("实收租金：%.2f 。其中应交租金：%.2f\n",money2,money1);
        }
    }
    else if(strcmp(type,"month")==0)
    {
        if(year1!=year2)
        {
            time=(year2-year1-1)*12+12-month1+month2;
        }
        else if(year1==year2)
        {
            time=month2-month1;
        }
        money1=term*month_price;
        if(time<term)
        {
            money0=(term-time)*month_price;
            money2=money1-money0;
            printf("本次租车时长为：%d月。经判断,为提前归还。\n",time);
            printf("实收租金：%.2f 。其中应交租金：%.2f  退款金额：%.2f\n",money2,money1,money0);
        }
        else if(time>term)
        {
            money0=(time-term)*month_price;
            money2=money1+money0;
            printf("本次租车时长为：%d月。经判断,为过期归还。\n",time);
            printf("实收租金：%.2f 。其中应交租金：%.2f  补交金额：%.2f\n",money2,money1,money0);
        }
        else if(time==term)
        {
            money2=money1;
            printf("本次租车时长为：%d月。\n",time);
            printf("实收租金：%.2f 。其中应交租金：%.2f\n",money2,money1);
        }
    }
    r->end_day=end_day;
    r->money2=money2;//实收租金。
    FILE *fp;
    fp=fopen("record.txt","w");//重新写文件。
    if(fp==NULL)
    {
        printf("文件打开失败！\n");
        exit(1);
    }
    r=head3;
    while(r->next!=NULL)
    {
        r=r->next;
        fprintf(fp,"%s\t%s\t%d\t%s\t%d\t%s\t%d\t%d\t%.2f\t%.2f\t%d\t%.2f\n",r->name,r->id,r->id_car,r->che_pai,
        r->number,r->type,r->term,r->start_day,r->deposit,r->money1,r->end_day,r->money2);
    }
    fclose(fp);
}

void trade_inquery(EE *head3)
{
    int n;
    menu4_1();//显示菜单。
    scanf("%d",&n);
    switch(n)
    {
        case 1:trade_inquery1(head3);break;
        case 2:trade_inquery2(head3);break;
        case 3:trade_inquery3(head3);break;
        default:printf("输入错误！拜拜。\n");
    }
}

void trade_inquery1(EE *head3)
{
    char name[20];
    int flag=0;
    printf("请输入客户姓名:");
    scanf("%s",name);
    EE *r;
    r=head3;
    while(r->next!=NULL)
    {
        r=r->next;
        if(strcmp(r->name,name)==0)
        {
            printf_3(r);
            flag++;
        }
    }
    if(flag==0)
        printf("Not Found!\n");
    return;
}

void trade_inquery2(EE *head3)
{
    char che_pai[10];
    int flag=0;
    printf("请输入车牌号:");
    scanf("%s",che_pai);
    EE *r;
    r=head3;
    while(r->next!=NULL)
    {
        r=r->next;
        if(strcmp(r->che_pai,che_pai)==0)
        {
            printf_3(r);
            flag++;
        }
    }
    if(flag==0)
        printf("Not Found!\n");
    return;
}

void trade_inquery3(EE *head3)
{
    int start_day;
    int flag=0;
    printf("请输入出租时间：(年月日,例:20240102)\n");
    scanf("%d",&start_day);
    EE *r;
    r=head3;
    while(r->next!=NULL)
    {
        r=r->next;
        if(r->start_day==start_day)
        {
            printf_3(r);
            flag++;
        }
    }
    if(flag==0)
        printf("Not Found!\n");
    return;
}

void trade_money(EE *head3)
{
    int end_day;
    float sum=0;
    printf("请输入需要查询月租金收入的日期：(年月,例:202401)\n");
    scanf("%d",&end_day);
    EE *r;
    r=head3;
    while(r->next!=NULL)
    {
        r=r->next;
        if((r->end_day)/100==end_day)
        {
            sum=sum+r->money2;
        }
    }
    printf("该月租金收入为：%.2f\n",sum);
}

void func(RR *head1,RR *s,EE *r,PP *q,PP *head4)//函数:用来在符合条件的number上加1.
{
    s=head1;
    while(s->next!=NULL)
    {
        s=s->next;
        if(r->id_car==s->id)
        {
            q=head4;
            while(q->next!=NULL)
            {
                q=q->next;
                if(strcmp(q->che_xing,s->che_xing)==0)
                {
                    q->number=q->number+1;
                    break;
                }
            }
        }
    }
}

void trade_number(EE *head3,RR *head1)
{
    int day;
    int sum=0;
    printf("请输入需要查询月车辆出租情况的日期：(年月,例:202401)\n");
    scanf("%d",&day);
    int day1;
    int month1;
    int month2;
    int year1;
    int year2;
    //根据车辆链表，将各种车型不重复的写进临时链表中，同时数量赋初值为0；
    RR *s;
    s=head1;
    PP *head4,*q,*p;
    head4=(PP*)malloc(sizeof(PP));
    head4->next=NULL;
    while(s->next!=NULL)
    {
        s=s->next;
        int flag=0;
        q=head4;
        while(q->next!=NULL)
        {
            q=q->next;
            if(strcmp(s->che_xing,q->che_xing)==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            p=(PP*)malloc(sizeof(PP));
            strcpy(p->che_xing,s->che_xing);
            p->number=0;
            p->next=NULL;
            q->next=p;
        }
    }
    //在业务链表中找到符合时间限制的车。
    EE *r;
    r=head3;
    while(r->next!=NULL)
    {
        r=r->next;
        day1=r->start_day%100;
        month1=r->start_day/100%100;
        month2=day%100;
        year1=r->start_day/10000;
        year2=day/100;
        if((r->start_day)/100<=day&&(r->end_day)/100>=day)//业务链表中符合条件，并且已经归还的车。
        {
            func(head1,s,r,q,head4);
        }
        else if((r->start_day)/100<=day&&r->end_day==0)//业务链表中符合条件，但还在出租中的车。
        {
            if(strcmp(r->type,"day")==0)//日租类型。
            {
                if(year1!=year2)//年份不同。
                {
                        if((day1+r->term)%30==0)
                        {
                            if((day1+r->term)/30-1>=12-month1+month2+(year2-year1-1)*12)
                                func(head1,s,r,q,head4);
                        }

                        else if((day1+r->term)%30!=0)//不满一月，算是一个月。
                        {
                            if((day1+r->term)/30>=12-month1+month2+(year2-year1-1)*12)
                                func(head1,s,r,q,head4);
                        }
                }
                else if(year1==year2)//年份相同。
                {
                    if(month1!=month2)
                    {
                        if((day1+r->term)%30==0)
                        {
                            if(month1+(day1+r->term)/30-1>=month2)
                                func(head1,s,r,q,head4);
                        }

                        else if((day1+r->term)%30!=0)
                        {
                            if(month1+(day1+r->term)/30>=month2)
                                func(head1,s,r,q,head4);
                        }
                    }
                    else if(month1==month2)
                    {
                        func(head1,s,r,q,head4);
                    }

                }
            }
            else if(strcmp(r->type,"month")==0)//月租类型。
            {
                if(year1!=year2)
                {
                    if(12-month1+month2+(year2-year1-1)*12<=r->term)
                        func(head1,s,r,q,head4);
                }
                else if(year1==year2)
                {
                    if(month2-month1<=r->term)
                        func(head1,s,r,q,head4);
                }
            }
        }
    }
    //指针从头开始，显示该月各个车型的出租情况。
    q=head4;
    printf("\n");
    while(q->next!=NULL)
    {
        q=q->next;
        printf("|-->  %s:  %d\n",q->che_xing,q->number);
    }
}
