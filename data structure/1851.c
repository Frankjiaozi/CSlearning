#include <stdio.h>
int T;
int n;
int sumweight=0;
int sumval=0;
int maxval;
struct item
{
    int weight;
    int val;
    float avrval;
};
typedef struct item Item;
void dfs(int x,Item item[])//2 3 4 5       10
{
    if(x==n)
    {
        if(sumweight<=T)
        {
            if(sumval>maxval)
            {
                maxval = sumval;
            }
        }
        return;
    }

        sumweight+=item[x].weight;
        sumval+=item[x].val;
    dfs(x+1,item);
    sumweight-=item[x].weight;
    sumval-=item[x].val;
    
    
    dfs(x+1,item);
    


}
int main()
{
    
    
    scanf("%d %d",&n,&T);
    Item item[1000];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&item[i].weight,&item[i].val);
        item[i].avrval = (float)item[i].val/(float)item[i].weight;
    }
    dfs(0,item);
    printf("%d",maxval);
 


}