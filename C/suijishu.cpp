#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
srand(time(0));
int a=rand();
a=a%100;
int n;
do
{
    printf("数字已经生成完毕：\n");
    scanf("%d",&n);
    
if(n>a) printf("太大了");
else if(n<a) printf("太小了") ;
} 
while (n!=a);

return 0;

}