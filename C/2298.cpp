#include <stdio.h>
void Arror(int n)//>+-+>
{
    printf(">+");
    for(int i=0;i<n-2;i++)
    {
        printf("-");
    }
    printf("+> ");

}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {   int N;
        scanf("%d",&N);
        for(int j=0;j<N;j++)
        {
            int A,B;
            scanf("%d %d",&A,&B);
            for(int m=0;m<B;m++)
            {
                Arror(A);
                printf("\n");
            }
        }
    }
}