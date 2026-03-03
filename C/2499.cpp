#include <stdio.h>
#include <string.h>
#include <math.h>


//补零
int  jiaozi(char result[])//01
{  char temp[100];
    int len=(int)strlen(result);
    if(len>=7) return 0;
    else
    {
    for(int i=0;i<7-len;i++)
    {
        temp[i]='0';
    }
    temp[7-len]='\0';
    strcat(temp,result);
    strcpy(result,temp);
    }
    return 1;
}




long long power(int n) {
    long long res = 1;
    for (int i = 0; i < n; i++) {
        res *= 2;
    }
    return res;
}

void reverse(char *str) {
    int len = strlen(str);
    char temp;
    for (int i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}



//10进制转2进制
void trans10to2(int x,char result[100])
{   int rest=x;
    int k=0;
    int add=0;
    while(rest>0)
    {   

        add=rest%2;
        result[k]=add+'0';
        rest=rest/2;
        k++;
    }
     result[k]='\0';
    reverse(result);
   
} 

int trans2to10(char result[])
{   int sum=0;
    int len=(int)strlen(result);//110
    for(int i=0;i<len;i++)
    {
        sum+=(result[i]-'0')*(int)power(len-i-1);
    }
    return sum;
}




int main()
{
    char result[100];
    int x;
    int temp;
    while(scanf("%d",&x)!=EOF && x!=0)
    {
    trans10to2(x,result);
    jiaozi(result);
    reverse(result);
    temp=trans2to10(result);
    printf("%c",temp);
    
    }
    //printf("%s",result);
}