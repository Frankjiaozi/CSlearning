#include <stdio.h>
int main()
{
   int s;
   while(scanf("%d",&s)!=EOF)
    {
        if(s>=90&&s<=100) printf("A\n");
        else if(s>=80&&s<=89) printf("B\n");
        else if(s>=70&&s<=79) printf("C\n");
        else if (s>=60&&s<=69) printf("D\n");
        else if (s>=0&&s<=59) printf("E\n");
        else printf("Score is error!\n");
    }
    return 0;
}