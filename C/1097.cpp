#include <stdio.h>
int main()
{
int m;
scanf("%d",&m);
//输入数组arr
int arr[m][m];
for(int i=0;i<m;i++)
{
    for(int j=0;j<m;j++)
    {   int a;
        scanf("%d",&a);
        arr[i][j]=a;
    }
}

//数组转置
for(int i=0;i<m;i++)
{
    for(int j=i;j<m;j++)
    {
        int temp=arr[j][i];
        arr[j][i]=arr[i][j];
        arr[i][j]=temp;
    }
}
int count=0;
for(int i=0;i<m;i++)
{   count=0;
    for(int j=0;j<m;j++)
    {   
        printf("%d",arr[i][j]);
        if(j!=m-1) printf(" ");
        count+=1;
    }
    if(count==m) printf("\n");
}



}