#include <stdio.h>
//定义结构体
struct veg
{
    char name[10];
    int avr_price;
    int weight;
    int total_price;
};

void swap(struct veg *a,struct veg *b)
{
    struct veg temp;
    temp= *a;
    *a=*b;
    *b=temp;
}


int main()
{
    int n,k;
while(scanf("%d %d",&n,&k)!=EOF&&n!=0&&k!=0)
{ 
//创建结构体数组
struct veg vegs[k];
//进行数据输入
for(int i=0;i<k;i++)
{
    scanf("%s",vegs[i].name);
    scanf("%d",&vegs[i].avr_price);
    scanf("%d",&vegs[i].weight);
    vegs[i].total_price=vegs[i].avr_price*vegs[i].weight;
}
//升序排序
for(int i=0;i<k-1;i++)
    {
        for(int j=0;j<k-1-i;j++)
        {
            if(vegs[j+1].avr_price<vegs[j].avr_price)
            { 
                swap(&vegs[j+1],&vegs[j]);
            }
        }
    }
/*for(int i=0;i<k;i++)
{
    printf("%d",vegs[i].avr_price);
}*/
//开始处理
//n是总共的钱，有K种水果

int result_weight=0;
for(int i=0;i<k;i++)
{
    if(vegs[i].total_price<=n)
    {
        n=n-vegs[i].total_price;
        result_weight+=vegs[i].weight;
    }
else if(vegs[i].total_price>n)//30    3 20
{
    result_weight+=n/vegs[i].avr_price;
    break;
}
}
printf("%d\n",result_weight);




}

}

