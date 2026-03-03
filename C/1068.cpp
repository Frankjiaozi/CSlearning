#include <stdio.h>
int main()
{
   int s;
   int i,j;
   while(scanf("%d",&s)!=EOF)
    {
      if(s==0) break;
      for(i=1;i<s+1;i++)
      {
         for(j=1;j<i+1;j=j+2)
            printf("*");
      printf("\n");}
      for(i=s;i>0;i--)
      {
         for(j=1;j<i;j++)
            printf("*");
      printf("\n");}





    }
    return 0;
}