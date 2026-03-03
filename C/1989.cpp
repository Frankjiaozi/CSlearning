#include <stdio.h>
int main()
{   
    int n;

    int k=0;
    int arr[100];
    int count=0;
    scanf("%d",&n);
    printf("%d=",n);
    while(n>1)
    {    
        int flag=0;
        for(int i=2;i*i<=n;i++)
        {   if(n%i==0) 
            {
                arr[k]=i;
                n=n/i;
                count++;
                k++;
                flag=1;
            }
        }
        if(flag==0) 
        {
            arr[k++]=n;
            break;
        }
    }
    //Êä³ö
    for(int i=0;i<count+1;i++)
    {
        printf("%d",arr[i]);
        if(i!=count) printf("*");
    }
    
}