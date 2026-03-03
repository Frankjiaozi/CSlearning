#include <stdio.h>


typedef struct Fruit{
    char name[101];
    int price;
}Fruit;

void sort(Fruit Fruit[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(Fruit[j].price>Fruit[j+1].price)
            {
                struct Fruit temp = Fruit[j];
                Fruit[j]=Fruit[j+1];
                Fruit[j+1]=temp;
            }
        }
    }
}


int main()
{   int T;
    scanf("%d",&T);//有T组数据
    for(int i=0;i<T;i++)
    {   
        int n;
        scanf("%d",&n);
        Fruit Fruit[n];
        for(int j=0;j<n;j++)
        {
            scanf("%s %d",Fruit[j].name,&Fruit[j].price);
        }
        sort(Fruit,n);
        for(int j=0;j<n;j++)
        {
            printf("%s %d\n",Fruit[j].name,Fruit[j].price);
        }
    }

}