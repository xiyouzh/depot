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
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}