#include<stdio.h>
#define N 10
int main()
{
    int i,j,t,n,a[N];
    printf("请输入数据个数\n");
    scanf("%d",&n);
    printf("请输入数据\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    for(i=1;i<n;i++)
    {
        t=a[i];
        for(j=i-1;j>-1&&a[j]>t;j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=t;
    }
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}