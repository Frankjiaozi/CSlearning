#include <stdio.h>

typedef struct people
{
    int index;
    int num;
    int condition;
}people;

int main()
{
    int n;
     while(scanf("%d",&n)!=EOF)
    {

    int count =n;
    int k=0;
    int add=1;

    people Peoples[n];
//初始化People数组
    for(int i=0;i<n;i++)
    {
        Peoples[i].index=i;
        Peoples[i].num=0;
        Peoples[i].condition=0;
    }

    while(count>1)
    {   
        
        while(Peoples[k].condition==1) k=(k+1)%n;
        Peoples[k].num=add;
        if(Peoples[k].num==3) 
        {
            count--;
            Peoples[k].condition=1;
        }
        k=(k+1)%n;
        add=(add%3)+1;
    }
        while(Peoples[k].condition==1) k=(k+1)%n;
        printf("%d\n",k+1); 
}
}
