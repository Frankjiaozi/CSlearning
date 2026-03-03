#include <stdio.h>
int judge(int x)
{   int flag=1;
    if(x==1) 
    {
        flag=0;
        return flag;
    }
    if(x==2) 
    {
        flag=1;
        return flag;
    }


    for(int i=3;i<x;i++)
    {
        if(x%i==0) flag=0;
    }
    return flag;
}





int Prime(int m,int n,int arr[])
{   int k=0;
    for(int i=m;i<=n;i++)
    {
        if(judge(i)==1) 
        {
            arr[k]=i;
            k++;
        }   
    }
    return k;
}



int main()
{   int m,n;
    int arr[1000];
    scanf("%d %d",&m,&n);
    int k=Prime(m,n,arr);
    for(int i=0;i<k;i++)
    {
        printf("%d\n",arr[i]);
    }
}