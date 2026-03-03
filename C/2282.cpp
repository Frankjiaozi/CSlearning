#include <stdio.h>
#include <string.h>

void sort(char STRS[][11],int n)
{   
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(strcmp(STRS[j],STRS[j+1])>0)
            {
                char temp[11];
                strcpy(temp,STRS[j]);
                strcpy(STRS[j],STRS[j+1]);
                strcpy(STRS[j+1],temp);
            }
        }
    }
}

int main()
{   int n;
    while(scanf("%d",&n)!=EOF && n!=0)
    {   
        char STRS[n][11];
        getchar();
        for(int i=0;i<n;i++)
        {
            scanf("%[^\n]",STRS[i]);
            getchar();
        }
        sort(STRS,n);
        for(int i=0;i<n;i++)
        {
            printf("%s\n",STRS[i]);
        }
    






    }
    
    
}