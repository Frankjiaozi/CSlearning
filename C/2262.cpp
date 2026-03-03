#include <stdio.h>
//建立坐标储存结构体
struct Point
{
    int x;
    int y;
};

//建立向量结构体
struct Vector
{
    int x;
    int y;
};
//建立向量运算函数
struct Vector vector_cal(struct Point point1, struct Point point2)//(x1,y1) (x2,y2)
{
    struct Vector vector_temp;
vector_temp.x=point2.x-point1.x;
vector_temp.y=point2.y-point1.y;
return vector_temp;
}

//建立叉积运算函数
int cross(struct Vector vector1, struct Vector vector2)
{
    int result=0;
    result=vector1.x*vector2.y-vector1.y*vector2.x;
    return result;
}
//数组相乘
int product(int arr[],int n)
{   int result=1;
    for(int i=0;i<n;i++)
    {
        result=result*arr[i];
    }
    return result;
}




int main()
{   
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0)
{
    //建立结构体数组
struct Point points[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&points[i].x,&points[i].y);
    }
    //建立储存每个边向量的数组，n个点有n条边
    struct Vector vectors[n];
    for(int i=0;i<n;i++)
    {
        vectors[i]=vector_cal(points[i],points[(i+1)%n]);
    }
    //建立叉积结果的数组
    int arr_product[n];
    for(int i=0;i<n;i++)
    {
        arr_product[i]=cross(vectors[i],vectors[(i+1)%n]);
    }

    int result=product(arr_product,n);

    if(result>0) printf("convex\n");
    else printf("concave\n");
}
return 0;
}