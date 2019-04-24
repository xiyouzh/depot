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
    int d=n,x;
    while(1)
    {
        d=d/2;
        for(x=0;x<d;x++)
        {
            for(i=x+d;i<n;i=i+d)
            {
                int k=i;
                int t=a[k];
                for(j=i-d;j>-1&&a[j]>t;j=j-d)
                {
                    a[j+d]=a[j];
                    k=j;
                }
                a[k]=t;
            }
        }
        if(d==1)
        {
            break;
        }
    }
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}