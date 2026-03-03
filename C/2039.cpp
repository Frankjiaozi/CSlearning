#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        char str[n][20]; 
       /// char result[n][20];
    getchar();
    for(int i=0;i<n;i++)
    {             char temp[20]={0};
        scanf("%s",temp);
        memmove(str[i],temp,20);//str[0]=a.exe    str[1]=b.exe
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<18;j++)
        {  
            if(str[i][j]=='e'&&str[i][j+1]=='x'&&str[i][j+2]=='e')
            {   char str_temp[20]={0};
                memmove(str_temp,str[i],j);//str_temp???????exe??????????????



                char result[20]={0};
                memmove(result,str[i],20);
                char hit[20]={0};
                memmove(str[i],hit,20);
                //???j????exe
                //printf("%s\n",str_temp);
                    for(int m=0;m<n;m++)
                    {
                        int flag=strncmp(str_temp,str[m],2);
                       if (flag==0) printf("%s\n",result);
                    }
                
            }           
        }
    }
}
    }
 
//x??????????????