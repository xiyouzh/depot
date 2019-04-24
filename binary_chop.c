#include<stdio.h>
#define N 10
int search(int *a,int n,int target)
{
    int first=0,last=n-1,mid;
    while(first<last)
    {
        mid=(first+last);
        if(a[mid]>target)
        {
            last=mid-1;
        }
        else if(a[mid]<target)
        {
            first=mid+1;
        }
        else
        {
            printf("该数的角标为:%d\n",mid);
            return 1;
        }
    }
    return 0;
}
int main()
{
    int i,j,t,n,a[N],flag=0,target;
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
    printf("请输入你要查找的数据\n");
    scanf("%d",&target);
    flag=search(a,n,target);
    if(flag)
    {
        printf("已找到该数!\n");
    }
    else
    {
        printf("无该数!\n");
    }
}