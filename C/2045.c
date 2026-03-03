#include <stdio.h>
#include <string.h>

int add(char *str, int pos, char ch)
 {
    int len = strlen(str);
    

    for (int i = len; i >= pos; i--) {
        str[i + 1] = str[i];
    }

    // 4. 在指定位置插入字符
    str[pos] = ch;
//printf("%s\n",str);
    return 0; // 插入成功
}

void reverse(char temp1[],char temp2[])
{
    int len=(int)strlen(temp1);
    for(int i=0;i<len;i++)
    {
        temp2[i]=temp1[len-1-i];
    }
    temp2[len]='\0';
  
}
int  main()
{   
    char str[100]={0};
    while(scanf("%s",str)!=EOF)
    {   char temp1[100]={0};
        int len=(int)strlen(str);
        int k=0;
        for(int i=0;i<len;i++)
        {
            if(str[i]!=',')
            {
                temp1[k]=str[i];
                k++;
            }
        }
        //printf("%s",temp1);
        char temp2[100]={0};
        reverse(temp1,temp2);
        int pos=3;
        while(pos<(int)strlen(temp2))
        {
            add(temp2,pos,',');
            pos+=4;
        }
        char temp3[100]={0};
        reverse(temp2,temp3);
        printf("%s\n",temp3);
    }

}