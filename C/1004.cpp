#include <stdio.h>
#include <stdlib.h>
int compare_asc(const void *a, const void *b) 
{
    return *(const int *)a - *(const int *)b;
}

int main()
{int n;
int win=0;
    scanf("%d",&n);
int tj[n];
    int qw[n];

for(int i=0;i<n;i++)
{   int a;
    scanf("%d",&a);
    if(a==0) break;
    tj[i]=a;
}
for(int i=0;i<n;i++)
{
    int a;
    scanf("%d",&a);
    if(a==0) break;
    qw[i]=a;
}
qsort(tj,n,sizeof(int),compare_asc);
qsort(qw,n,sizeof(int),compare_asc);
int start_tj=0;
int end_tj=n-1; 
int start_qw=0;
int end_qw=n-1;
while(start_tj<=end_tj)
{
if(tj[end_tj]>qw[end_qw])
{win+=1;
end_qw-=1;
end_tj-=1;
}
else if (tj[end_tj]<qw[end_qw])
{
    start_tj+=1;
    end_qw-=1;//tj最慢比qw最快
}
else if (tj[end_tj]==qw[end_qw])
{
    if(tj[start_tj]>qw[start_qw])
    {
    win+=1;
    start_qw+=1;
    start_tj+=1;
    }
    else
    {
    start_tj+=1;
    end_qw-=1;
    }
    
}

}
if(win>n/2) printf("YES\n");
else printf("NO\n");
}
