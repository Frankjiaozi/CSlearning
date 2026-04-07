#include <stdio.h>

struct pos
{
    int x;
    int y;
};
typedef struct pos pos;


void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}


int main()
{
    int n;
    scanf("%d",&n);
    int arr[n][n];
    pos min;
    min.x=0;
    min.y=0;
    pos lessmin;
    lessmin.x=0;
    lessmin.y=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
            if(arr[i][j]<arr[min.x][min.y])
            {
                min.x=i;
                min.y=j;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]<arr[lessmin.x][lessmin.y] && arr[i][j]!=arr[min.x][min.y])
            {
                lessmin.x=i;
                lessmin.y=j;
            }
        }
    }
swap(&arr[0][0],&arr[min.x][min.y]);
swap(&arr[n-1][n-1],&arr[lessmin.x][lessmin.y]);
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        printf("%d",arr[i][j]);
        if(j!=n-1)
        {
            printf(" ");
        }
    }
    printf("\n");
}


}
