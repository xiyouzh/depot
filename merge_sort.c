#include<stdio.h>
#define N 10
int merge(int r[],int s[],int x1,int x2,int x3) //将左右两个区域的数进行比较，使较小的数放在左区域
{
    int i,j,k;
    i=x1;       //第一部分的起始位置
    j=x2+1;     //第二部分的起始位置
    k=x1;
    while((i<=x2)&&(j<=x3))        //当i和j在两个要合并的部分时
    {
        if(r[i]<=r[j])          //筛选较小的元素放在数组s中
        {
            s[k]=r[i];
            i++;
            k++;
        }
        else
        {
            s[k]=r[j];
            j++;
            k++;
        }
    }
        while(i<=x2)            //将x1~x2范围中的未比较的元素依次放进数组r中
        {
            s[k++]=r[i++];
        }
        while(j<=x3)           //将x2+1~x3范围中的未比较的元素依次加到数组r中
        {
            s[k++]=r[j++];
        }
    return 0;
}
int merge_sort(int r[],int s[],int m,int n)
{
    int p;
    int t[20];
    if(m==n)
    {
        s[m]=r[m];
    }
    else
    {
        p=(m+n)/2;
        merge_sort(r,t,m,p);
        merge_sort(r,t,p+1,n);
        merge(t,s,m,p,n);
    }
    return 0;
}
int main()
{
    int n,a[N],i;
    printf("请输入数据个数\n");
    scanf("%d",&n);
    printf("请输入数据个数\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    merge_sort(a,a,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}