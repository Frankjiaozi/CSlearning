#include <stdio.h>
int main()
{
int m;
scanf("%d",&m);
int arr[m][m];

for(int i=0;i<m;i++)
{
for(int j=0;j<m;j++)
{   int a;
    scanf("%d",&a);
    arr[i][j]=a;
}
}
int flag=1;
for(int i=1;i<m;i++)
{
    for(int j=0;j<=i-1;j++)
    {
       if(arr[i][j]!=0)  flag=0;
    }
}
if (flag==0) printf("NO");
else if(flag==1) printf("YES");
}