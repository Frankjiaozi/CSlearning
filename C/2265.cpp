#include <stdio.h>
#include <string.h>
int strcmp_self(char str1[],char str2[])//前提是先从小到大排序
{   
    char *p1=str1;
    char *p2=str2;
    while(*p1!='\0' && *p2!='\0')
    {
        if(*p1==*p2)
        {
            p1++;
            p2++;
        }
        else if(*p1>*p2) 
        {
            return *p1-*p2;
        }
        else return *p1-*p2;
    }
    return 0;
}


int main()
{  
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
    char str1[100];
    char str2[100];
    scanf("%s",str1);
    scanf("%s",str2);
    printf("%d\n",strcmp_self(str1,str2));
    }
}