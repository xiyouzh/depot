#include<stdio.h>
#include<string.h>
typedef struct stack            //模拟栈
{
    char s[100];
    int top;        //栈顶
    int base;       //栈底
}STACK,*Stack;
void init(Stack S)          //栈的初始化
{
    S->top=0;
    S->base=0;
}
void Pop(Stack S,char *e)       //出栈操作
{
    *e=S->s[--S->top];
}
void Push(Stack S,char a)       //入栈操作
{
    S->s[S->top++]=a;
}
int main()
{
    STACK S;
    char e;
    int i,j,h;
    char a[200];
    while(gets(a)!=NULL)
    {
        h=strlen(a);
        init(&S);
        for(i=0;i<h;i++)
        {
            if(a[i]=='#')
            {
                Pop(&S,&e);
            }
            else if(a[i]=='@')
            {
                init(&S);
            }
            else
            {
                Push(&S,a[i]);
            }
        }
        while(S.base!=S.top)
        {
            printf("%c",S.s[S.base++]);
        }
        printf("\n");
    }
    return 0;
}