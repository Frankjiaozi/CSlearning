#include <stdio.h>
float sum(int m,float *arr)
{float sum=0;
    for(int i=0;i<m;i++)
    {
        sum=sum+arr[i];
    }
return sum;
}
int main()
{   int n,m;
    scanf("%d,%d",&n,&m);
    float arr_result[n];
    int indices[n];
    for (int i = n; i>=1; i--) {
        indices[i] =n-i+1;
    }
    
    for(int i=0;i<n;i++)
    {           float arr_temp[m];
                for(int j=0;j<m;j++)
                {   float a;
                    scanf("%f",&a);
                    arr_temp[j]=a;
                }
                //选出temparr中的最大最小
            float min=arr_temp[0],max=arr_temp[0];
            for(int i=0;i<m;i++)
            {
            if(arr_temp[i]<min) min=arr_temp[i];
            if(arr_temp[i]>max) max=arr_temp[i];
            }
        float avrsum=(sum(m,arr_temp)-max-min)/(float)(m-2);
        
            arr_result[i]=avrsum;
    }
for(int i=0;i<n-1;i++)//9 4 2 3 6 7 8 
{
    for(int j=0;j<n-1-i;j++)
    {
        if(arr_result[j]>arr_result[j+1])
        {
            int temp=arr_result[j+1];
            arr_result[j+1]=arr_result[j];
            arr_result[j+1]=temp;
        }
    int idx_temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = idx_temp;
    }
}
for (int i = 0; i < n; i++) {
        printf("第%d名：%d号选手,得分:%.2f\n", i + 1, indices[i], arr_result[i]);
    }

    
}