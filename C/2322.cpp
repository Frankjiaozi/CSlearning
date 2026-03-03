#include  <stdio.h>
#include <string.h>
#include <math.h>
void trans_ten_to_two(int x,char result[])//6
{
    
    int a=0;
    while(x>0)
    {   int temp=x%2;
        x=x/2;
        result[a]=temp+'0';
        a++;
    }
    result[a]='\0';
}



int trans_two_to_ten(int arr[],int length)
{//110
     int result=0;
    for(int i=0;i<length;i++)
    {
        result+=arr[i]*pow(2,length-i-1);
    }


return result;
}

int main()
{   char x;
    while(scanf("%c",&x)!=EOF)
    {   
        if(x=='D')
        {   
            int n;
            scanf("%d",&n);
            char result[1000];
            trans_ten_to_two(n,result);

            for(int i=0;i<8-(int)strlen(result);i++)
            {
                printf("%c",'0');
            }
            for(int i=strlen(result)-1;i>=0;i--)
            {   
                printf("%c",result[i]);
                
            }
             printf("\n");
        }
        else if(x=='B')
        {
            char  str[1000];
            scanf("%s",str);
            int length=strlen(str);
            int arr[length];
            //字符串转化为数组
            for(int i=0;i<length;i++)
            {
                arr[i]=str[i]-'0';
            }
            int result=trans_two_to_ten(arr,length);
            printf("%d\n",result);


        }
    }

    
}