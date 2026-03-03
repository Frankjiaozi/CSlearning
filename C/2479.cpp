#include <stdio.h>
#include <string.h>
void reverse(char str[])
{   
    char temp[100]={0};
    int k=0;
    for(int i=(int)strlen(str)-1;i>=0;i--)
    {
        temp[k++]=str[i];
    }
    strcpy(str,temp);
}



void delete_str(char str[],int pos)// 123456788
{
    char temp1[100]={'0'};
    char temp2[100]={'0'};
    int k=0;
    for(int i=pos+1;i<(int)strlen(str);i++)
    {
        temp1[k++]=str[i];
    }
    k=0;
    for(int i=0;i<pos;i++)
    {
        temp2[k++]=str[i];
    }
    strcpy(str,temp2);
    strcat(str,temp1);
    printf("%s",str);
    

}

int n,m,p;
int main()
{
    scanf("%d %d %d",&n,&m,&p);
    int count=n;
    char str[n+1]={'0'};
    for(int i=0;i<n;i++)
    {
        str[i]=i;
    }

    while(count>m-1)
    {   
        
        delete_str(str,m);
        reverse(str);
        count--;
    }
    printf("%s",str);

    
    
    

}