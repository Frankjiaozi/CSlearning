#include <stdio.h>
int main()
{
int n=0;
float h=100.0;
float s=100.0;
while(scanf("%d",&n)!=EOF)
{
for(int i=1;i<=n-1;i++)
{
h=h/2.0;
s=s+h*2;
}
h=h/2.0;
printf("共经过%.5f米\n第n次反弹%.5f米",s,h);
}

}