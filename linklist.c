#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#define N 10
typedef struct student
{
	char name[10];
	int number;
	int age;
	int mark;
	struct student  *llink,*rlink;
}stu;
stu *create(int n)
{
	stu *pend,*phead,*pnew;
	int i;
	if((phead=(stu *)malloc(sizeof(stu)))==NULL)
	{
		printf("不能分配内存!\n");
		exit(0);
	}
	phead->name[0]='\0';
	phead->llink=NULL;
	phead->rlink=NULL;
	pend=phead;
	for(i=0;i<n;i++)
	{
		if((pnew=(stu *)malloc(sizeof(stu)))==NULL)
		{
			printf("不能分配内存空间\n");
			exit(0);
		}
		pend->rlink=pnew;
		printf("请输入第%d个人的信息\n",i+1);
		printf("姓名:");
		scanf("%s",pnew->name);
		printf("学号:");
		scanf("%d",&pnew->number);
		printf("年龄:");
		scanf("%d",&pnew->age);
		printf("分数:");
		scanf("%d",&pnew->mark);
		pnew->llink=pend;
		pnew->rlink=NULL;
		pend=pnew;
	}
	phead->llink=pnew;
	pend->rlink=phead;
	return phead;
}
int print(stu *phead)
{
	int n;
	stu *p;
	p=phead->rlink;
	printf("数据信息为:\n");
	while(p!=phead)
	{
		printf("姓名:%s ",p->name);
		printf("学号:%d ",p->number);
		printf("年龄:%d ",p->age);
		printf("分数:%d\n",p->mark);
		p=p->rlink;
	}
	printf("\n");
}
stu *search(stu *phead,char *x)
{
	stu *p;
	char *y;
	p=phead->rlink;
	while(p!=phead)
	{
		y=p->name;
		if(strcmp(y,x)==0)
		{
			printf("姓名:%s ",p->name);
			printf("学号:%d ",p->number);
			printf("年龄:%d ",p->age);
			printf("分数:%d\n",p->mark);
			return p;
		}
		else
			p=p->rlink;
	}
	printf("没有找到该数!\n");
}
int insert(stu *phead)				//插入在开头
{
	stu *pnew;
	if((pnew=(stu *)malloc(sizeof(stu)))==NULL)
	{
		printf("不能分配空间\n");
		exit(0);
	}
	printf("请输入你要插入的人的信息\n");
	printf("姓名 ");
	scanf("%s",pnew->name);
	printf("学号 ");
	scanf("%d",&pnew->number);
	printf("年龄 ");
	scanf("%d",&pnew->age);
	printf("分数");
	scanf("%d",&pnew->mark);
	printf("\n");
	pnew->rlink=phead->rlink;
	phead->rlink=pnew;
	pnew->llink=phead;
	(pnew->llink)->llink=pnew;
}
int Delete(stu *phead)
{
	int n,i;
	stu *p;
	p=phead->rlink;
	printf("请输入要删除的结点\n");
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		p=p->rlink;
	}
	p->llink->rlink=p->rlink;
	p->rlink->llink=p->llink;
	free(p);
}
int change(stu *phead)
{
	stu *p;
	int i,n;
	printf("请输入你要更改数据的结点\n");
	scanf("%d",&n);
	p=phead->rlink;
	for(i=1;i<n;i++)
	{
		p=p->rlink;
	}
	printf("新的姓名:");
	scanf("%s",p->name);
	printf("新的学号:");
	scanf("%d",&p->number);
	printf("新的年龄:");
	scanf("%d",&p->age);
	printf("新的分数:");
	scanf("%d",&p->mark);
	printf("\n");
	printf("更改成功!\n");
}
int main()
{
	int num;
	char stuname[20];
	stu *phead,*searchpoint;
	printf("请输入录入信息人数\n");
	scanf("%d",&num);
	phead=create(num);
	insert(phead);
	printf("请输入你要查找的人的姓名\n");
	scanf("%s",stuname);
	searchpoint=search(phead,stuname);
	Delete(phead);
	change(phead);
	print(phead);
}
