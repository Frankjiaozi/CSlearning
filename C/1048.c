 #include <stdio.h>

void sort(int arr[],int m)
{
    for(int i=0;i<m-1;i++)
    {
        for(int j=0;j<m-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}


int main()
{
    int n;
    scanf("%d",&n);
    for(int z=0;z<n;z++)
    {
        int m;
        scanf("%d",&m);
        int arr[m];
        for(int i=0;i<m;i++)
        {
            scanf("%d",&arr[i]);
        }
    sort(arr,m);
    

    //开始统计
    int left=0; int right=0; //1 1 1 2  2 4  4 4 4
    int max=0;
    while(right<=m)
    {   
        int temp=0;
         do
         {
            temp++;
            right++;
            if(right==m)
            {
                if(max<temp) max=temp;
            }
         } while (arr[right]==arr[left]);
         if(max<temp) max=temp;
         left = right;
         
    }
    printf("%d\n",max);




    }
}