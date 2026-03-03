#include <stdio.h>
#include <string.h>
//交换函数
void swap(char *a,char *b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
}



//对字符串进行排序
void sort(char arr[])
{
    for(int i=0;i<(int)strlen(arr)-1;i++)
    {
        for(int j=0;j<(int)strlen(arr)-1-i;j++)
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
    char str[100];
    char STRS[100][100];
    char value[100][100];
    scanf("%[^*]",str);
    char *delim = " \t\n\r"; // 扩展分隔符，支持常见空白字符
    char* token=strtok(str,delim);
    int k=0;//等于切割后的字符串的数量
    while(token!=NULL)
    {   
        strcpy(STRS[k],token);
        token=strtok(NULL,delim);
        k++;
    }
    int num=k;
    //给初始字典排序
    for(int i=0;i<num-1;i++)// 2 3 4 54 65 1 
    {   for(int j=0;j<num-1-i;j++)
        {
            if(strcmp(STRS[j],STRS[j+1])>0)
            {
                char temp11[100];
                strcpy(temp11,STRS[j]);
                strcpy(STRS[j],STRS[j+1]);
                strcpy(STRS[j+1],temp11);
            }
        }
    }

    //value这个字符串数组按字典排序过后
    for(int i=0;i<k;i++)
    {
        strcpy(value[i],STRS[i]);
        sort(value[i]);
        //printf("%s\n",value[i]);
    }






    //处理用户输入
    while(getchar()!='\n');
    char str_input[100];
    char STR_inputs[100][100];
    while(scanf("%s",str_input)!=EOF)
    {
    char* token1=strtok(str_input,delim);
    int m=0;//等于切割后的字符串的数量
    while(token1!=NULL)
    {   
        strcpy(STR_inputs[m],token1);
        //printf("%s\n",token1);
        token1=strtok(NULL,delim);
        m++;
    }
int num_input=m;
for(int i=0;i<num_input;i++)
{
 sort(STR_inputs[i]);   
}


//开始判断

for(int i=0;i<num_input;i++)
{   int flag=0;
    for(int j=0;j<num;j++)
    {
        if(strcmp(STR_inputs[i],value[j])==0)
        {
            printf("%s ",STRS[j]);
            flag=1;
        }
    }
    if(flag==1) printf("\n");
    if(flag==0) printf("%s\n",":(");
} 
}
}