#include <stdio.h>

typedef struct Homework
{
    int ddl;
    int happy_value;
}Homework;

//…˝–Ú≈≈–Ú
void sort(Homework arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j].happy_value<arr[j+1].happy_value)
            {
                Homework temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int sum_arr(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    return sum;
}
int main()
{
    int n;
while(scanf("%d",&n)!=EOF)
{
    Homework arr[n];
for(int i=0;i<n;i++)
{
    scanf("%d",&arr[i].ddl);
}
for(int i=0;i<n;i++)
{
    scanf("%d",&arr[i].happy_value);
}



sort(arr,n);
int jiji[n];
int pos=0;

for(int i=0;i<n;i++)
{
    jiji[i]=0;
}

for(int i=0;i<n;i++)
{int flag=0;
pos=arr[i].ddl-1;
while(flag==0 && pos>=0)
{

if(jiji[pos]==0)
{
    jiji[pos]=arr[i].happy_value;
    flag=1;
}
pos--;
}
}

int sum=0;
for(int i=0;i<n;i++)
{
    sum+=arr[i].happy_value;
}


int result=sum-sum_arr(jiji,n);
printf("%d\n",result);

}
}