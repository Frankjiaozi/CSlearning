#include <stdio.h>
int main()
{int a=0;
while (scanf("%d",&a)!=EOF)
{int i=0;double s=0;
do{i=i+1;
    
s=s+1.0/i;
} while (s<=a);
printf("s=%.4lf,n=%d\n",s,i); 
}
}