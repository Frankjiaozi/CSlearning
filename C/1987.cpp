#include <stdio.h>
int main()
{   int n;
    scanf("%d",&n);
    int arr[n][n];
    float result[n][n];
    //输入
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)

        {
            scanf("%d",&arr[i][j]);
        }
    }

    //处理
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)

        {
            result[i][j]=(float)arr[i][j]/(float)arr[i][i];
        }
    }
    //输出
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)

        {
            printf("%.2f",result[i][j]);
            if(j!=n-1) printf(" ");
            if(j==n-1) printf("\n");
        }
    }
}