#include <stdio.h>


void sort(int **p,int n)
{
    for(int i=0;i<n-1;i++)

    {
        for(int j=0;j<n-1-i;j++)
        {
            if(**(p+j)>**(p+j+1))
            {
                int *temp=*(p+j);
                *(p+j)=*(p+j+1);
                *(p+j+1)=temp;
            }
        }
    }
}



int main()
{   int n;
    while(scanf("%d",&n)!=EOF && n!=0)
    {   int arr[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
int *arr_p[n];
    for(int i=0;i<n;i++)
        {
           arr_p[i]=&arr[i];
        }
        sort(arr_p,n);

    for(int i=0;i<n;i++)
        {
          printf("%d ",*arr_p[i]);
          if(i==n-1) printf("\n");
        }
    }


}