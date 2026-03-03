#include <stdio.h>
#include <string.h>
//jiaozi

void transfer(char str[],int len,int arr[])
{  
    for(int i=0;i<len;i++)
    {
        arr[i]=(int)(str[i]-'0');
    }
}


void swap(char *a,char *b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
}


void bubble_sort(char arr[],int len)
{
    for(int i=0;i<len-1;i++)
    {
        for(int j=0;j<len-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}


int main()
{   
    
    char str1[100]={0};
    char str2[100]={0};
    scanf("%s",str1);
    scanf("%s",str2);
    strcat(str1,str2);
    int len = (int)strlen(str1);

    bubble_sort(str1,len);
    for(int i=0;i<len;i++)
    {
        printf("%c",str1[i]);
    }

}