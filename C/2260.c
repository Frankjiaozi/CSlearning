#include <stdio.h>
#include <string.h>
void trans(int x,char str[])//12345
{   int i=0;
    while(x>0)
    {   
       
        str[i]=x%10+'0';
        x=x/10;
        i++;
    }
    str[i]='\0';
int len = strlen(str);
char temp[len+1];
for(int i=len-1;i>=0;i--)
{
temp[len-i-1]=str[i];
temp[len]='\0';

}
strcpy(str,temp);
}


int judge(char str[])
{
    int flag = 0;
    int len = (int)strlen(str);
    
    // 遍历所有字符（从第0位到最后1位，不遗漏任何位置）
    for (int i = 0; i < len; i++)
    {
        // 规则1：判断当前字符是否是'4'（覆盖所有位置，包括最后一位）
        if (str[i] == '4')
        {
            flag = 1;
            break; // 找到即退出，无需继续判断
        }
        
        // 规则2：判断当前字符+下一位是否是'38'（先确保i+1不越界）
        if (i + 1 < len && str[i] == '3' && str[i+1] == '8')
        {
            flag = 1;
            break;
        }
    }
    
    return flag;
}
int main()
{
    int m,n; 
    
    while(scanf("%d %d",&m,&n)!=EOF && m!=0 && n!=0)
    {   int count = 0;
        char STRS[n-m+1][100];
        int k=0;
        for(int i=m;i<=n;i++)
        {
            trans(i,STRS[k]);
            k++;
        }
        for(int i=0;i<k;i++)
        {
            if(judge(STRS[i])==0)
            {
                count++;

            }
        }
        printf("%d\n",count);
    }
}