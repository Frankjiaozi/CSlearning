#include <stdio.h>
//实现阶乘
int   facotorial(int x)
{
    for(int   i=x-1;i>=1;i--)
    {
        x=x*i;
    }
    if(x==0) return 1;
    else return x; 
    
}
//实现Anm
int   A(int m,int n)

{   int   result;
    { result=facotorial(m)/facotorial(m-n);}

    return result;
}
//实现Cnm
int   C(int  m,int  n)
{
    int   result=A(m,n)/A(n,n);
    return result;
}





int  main()
{   int   n,m;
    scanf("%d %d",&n,&m);
    printf("%d\n",C(n,m));
}