#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100        //存储空间的初始分配量
#define STACKINCREMENT 10          //存储空间分配增量
typedef struct{
    int *base;              //在栈构造之前和销毁之后，base的值为NULL
    int *top;               //栈顶指针
    int stacksize;          //当前已分配的存储空间，以元素为单位
}SqStack;
int InitStack(SqStack *S)           //构造一个空栈S
{
    S->base=(int *)malloc(STACK_INIT_SIZE*sizeof(int));
    if(!S->base)
    {
        exit(0);
    }
    S->top=S->base;
    S->stacksize=STACK_INIT_SIZE;
    return 0;
}
int push(SqStack *S,int e)             //插入元素e为新的栈顶元素
{
    if(S->top-S->base>=S->stacksize)        //栈满，追加存储空间
    {
        S->base=(int *)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(int));
        if(!S->base)
        {
            exit(1);
        }
        S->top=S->base+S->stacksize;
        S->stacksize+=STACKINCREMENT;
    }
    *S->top++=e;
    return 0;
}
//若栈S为空栈，则返回1,否则返回0
int StackEmpty(SqStack *S){
    if(S->top==S->base)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//若栈不空，则删除S的栈顶元素，则e返回其值，并返回0，否则返回1
int Pop(SqStack *S,int *e){
    if(S->top==S->base)
    {
        return 1;
    }
    *e=*--S->top;
    return 0;
}
void main()
{
    SqStack S;
    int e;
    InitStack(&S);
    int N;
    printf("请输入一个十进制数\n");
    scanf("%d",&N);
    while(N)
    {
        push(&S,N%8);
        N=N/8;
    }
    while(!StackEmpty(&S))
    {
        Pop(&S,&e);
        printf("%d",e);
    }
    printf("\n");
}