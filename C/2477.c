#include <stdio.h>
#include <string.h>                                    
#include <stdlib.h>

int check_number(char character)
{   
    if (character>='0' && character<='9') 
    {
        return 1;
    }
    return 0;
}
int checknum(char character,int *p)
{
    if((character>='0' && character<='9')||character=='.'||character=='+'||character=='-'||character=='e')
    {
        if(character=='.')
        {
            (*p)++;
            //printf("p=%d\n",*p);
        }
        return 1;
    }
    return 0;
}

int check_e(char str[])
{
    int len = strlen(str);
    for(int i = 0;i<len;i++)
    {
        if(str[i]=='e' && check_number(str[i-1])==1)
        {
            return i;
        }
    }
        return -1;
}


int main()
{  
    int flagpoint=0;
    int *p=&flagpoint;
    char str[100];
    char result[100];
    scanf("%s",str);
    int index=check_e(str);
    char *back=&str[index];
    char *front=&str[index];
    while(checknum(*back,p)==1 && flagpoint<=1)
    {
        back--;
    }
    //printf("%c\n",*back);
     while(checknum(*front,p)==1)
    {
        front++;
    }
    //printf("%c\n",*front);
    back++;
     front--;
     int k=0;
    while(back<=front)
    {   
        result[k++]=*back;
        back++;
    }
    double yeyeye=atof(result);
    printf("%f",yeyeye);

}