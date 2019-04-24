#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
    char name[20];
    int num;
    int age;
    int mark;
    struct student *next;
}stu;
int count;
stu *create()
{
    stu *phead=NULL;
    stu *pnew,*pend;
    int count=0;        //初始化链表长度
    pnew=pend=(stu *)malloc(sizeof(stu));
    printf("请输入学生信息\n");
    printf("姓名:");
    scanf("%s",pnew->name);
    printf("学号:");
    scanf("%d",&pnew->num);
    printf("年龄:");
    scanf("%d",&pnew->age);
    printf("分数:");
    scanf("%d",&pnew->mark);
    printf("\n");
    while(pnew->num!=0)
    {
        count++;
        if(count==1)
        {
            pnew->next=NULL;
            phead=pnew;
            pend=pnew;
        }
        else
        {
            pnew->next=NULL;
            pend->next=pnew;
            pend=pnew;
        }
        pnew=(stu *)malloc(sizeof(stu));
        printf("姓名:");
        scanf("%s",pnew->name);
        printf("学号:");
        scanf("%d",&pnew->num);
        printf("年龄:");
        scanf("%d",&pnew->age);
        printf("分数:");
        scanf("%d",&pnew->mark);
        printf("\n");
    }
    free(pnew);
    return phead;
}
int print(stu *phead)
{
    stu *temp;
    int index=1;
    printf("共有%d个学生\n",count);
    temp=phead;
    while(temp!=NULL)
    {
        printf("第%d个学生信息\n",index);
        printf("姓名:%s",temp->name);
        printf("学号:%d",&temp->num);
        printf("年龄:%d",&temp->age);
        printf("分数:%d",&temp->mark);
        printf("\n");
        temp=temp->next;
        index++;
    }
}
//头插
stu *insert(stu *phead)
{
    stu *pnew;
    printf("请输入在开头插入的学生信息\n");
    pnew=(stu *)malloc(sizeof(stu));
    printf("姓名:");
    scanf("%s",pnew->name);
    printf("学号:");
    scanf("%d",&pnew->num);
    printf("年龄:");
    scanf("%d",&pnew->age);
    printf("分数:");
    scanf("%d",&pnew->mark);
    printf("\n");
    pnew->next=phead;
    phead=pnew;
    count++;
    return phead;
}
//尾插
stu *insert1(stu *phead)
{
    stu *pnew,*p=phead;
    while(p&&p->next!=NULL)
    {
        p=p->next;
    }
    printf("请输入在结尾插入的学生信息\n");
    pnew=(stu *)malloc(sizeof(stu));
    printf("姓名:");
    scanf("%s",pnew->name);
    printf("学号:");
    scanf("%d",&pnew->num);
    printf("年龄:");
    scanf("%d",&pnew->age);
    printf("分数:");
    scanf("%d",&pnew->mark);
    printf("\n");
    p->next=pnew;
    pnew->next=NULL;
    count++;
    return phead;
}
//中间学生后插入
stu *insert2(stu *phead)
{
    int n;
    stu *pnew,*p=phead;
    printf("请输入学号后插入\n");
    scanf("%d",&n);
    while(p&&p->num!=n)
    {
        p=p->next;
    }
    printf("请输入在学号为n的学生后插入的学生信息\n",n);
    pnew=(stu *)malloc(sizeof(stu));
    printf("姓名:");
    scanf("%s",pnew->name);
    printf("学号:");
    scanf("%d",&pnew->num);
    printf("年龄:");
    scanf("%d",&pnew->age);
    printf("分数:");
    scanf("%d",&pnew->mark);
    printf("\n");
    pnew->next=p->next;
    p->next=pnew;
    count++;
    return phead;
}
int Delete(stu *phead)
{
    stu *temp,*pre;
    int i,index;
    temp=phead;
    pre=temp;
    printf("请输入要删除第几个学生\n");
    scanf("%d",&index);
    printf("删除第%d个学生!\n",index);
    for(i=1;i<index;i++)
    {
        pre=temp;
        temp=temp->next;
    }
    pre->next=temp->next;
    free(temp);
    count--;
}
int change(stu *phead)
{
    int willchange;
    stu *p;
    printf("请输入你要更改学生的学号\n");
    scanf("%d",&willchange);
    p=phead->next;
    while(p!=NULL)
    {
        if(p->num==willchange)
        {
            printf("请输入新的信息\n");
            printf("姓名:");
            scanf("%s",p->name);
            printf("学号:");
            scanf("%d",&p->num);
            printf("年龄:");
            scanf("%d",&p->age);
            printf("分数:");
            scanf("%d",&p->mark);
            printf("\n");
            printf("更改成功!\n");
            printf("新数据为:\n");
            printf("姓名:%s",p->name);
            printf("学号:%d",&p->num);
            printf("年龄:%d",&p->age);
            printf("分数:%d",&p->mark);
            printf("\n");
        }
        p=p->next;
    }
}
int search(stu *phead)
{
    int willsearch;
    stu *p;
    p=phead->next;
    printf("请输入你要查询信息学生的学号\n");
    scanf("%d",&willsearch);
    while(p!=NULL)
    {
        if(p->num==willsearch)
        {
            printf("查询成功!\n");
            printf("学生信息为:\n");
            printf("姓名:%s",p->name);
            printf("学号:%d",&p->num);
            printf("年龄:%d",&p->age);
            printf("分数:%d",&p->mark);
            printf("\n");
        }
        p=p->next;
    }
}
int main()
{
    struct student *phead;
    phead=create();
    phead=insert(phead);
    phead=insert1(phead);
    phead=insert2(phead);
    Delete(phead);
    change(phead);
    search(phead);
    print(phead);
}