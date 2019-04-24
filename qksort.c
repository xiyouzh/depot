#include<stdio.h>
#define N 10
void swap(int *,int *);
void quicksort(int *,int ,int );
void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
    return;
}
void quicksort(int *a,int low,int high)
{
    int i=low;
    int j=high;
    int k=a[low];
    if(low>=high)
    {
        return;
    }
    while(low<high)
    {
        while(low<high&&k<=a[high])
        {
            --high;
        }
        if(k>a[high])
        {
            swap(&a[low],&a[high]);
            ++low;
        }
        while(low<high&&k>=a[low])
        {
            ++low;
        }
        if(k<a[low])
        {
            swap(&a[low],&a[high]);
            --high;
        }
    }
    quicksort(a,i,low-1);
    quicksort(a,low+1,j);
}
int main(void)
{
    int i,j,n,a[N];
    printf("请输入数据\n");
    scanf("%d",&n);
    printf("请输入数据\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    quicksort(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}