#include <stdio.h>
int prime_num(int x)
{   int flag=1;
    for(int i=2;i<x;i++)
    {
        if(x%i==0) flag=0;
    }
    return flag;
}



int main()
{   

    //1-200之内的奇素数
    int arr[45];
    int a=0;
    for(int i=3;i<200;i+=2)
    {   
        if(prime_num(i)==1) 
        {
            arr[a]=i; 
            //printf("%d ",arr[a]);
            a++;
         }
    }

int n;

while(scanf("%d",&n)!=EOF&&n!=0)
{   int count=0;
    for(int a=0;a<44;a++)
    {
        for(int b=a;b<44;b++)
        {
            for(int c=b;c<44;c++)
            {
                if(arr[a]+arr[b]+arr[c]==n) 
                {
                    //printf("%d %d %d\n",arr[a],arr[b],arr[c]);
                    count+=1;
                }
            }
        }
    }
    printf("%d\n",count);
}
}
