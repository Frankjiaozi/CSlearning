    #include <stdio.h>

    int sum1(int arr[],int m,int pos)
    {
        int s=0;
        for(int i=pos;i<m;i++)
        {
            s+=arr[i];
        }
        return s;
    }

    int sum2(int arr[],int m,int pos)
    {
        int s=0;
        for(int i=pos;i>=0;i--)
        {
            s+=arr[i];
        }
        return s;
    }
    int main()
    {
        int count=0;
        int n;
        scanf("%d",&n);//n对新人
        int m=n*2;//m个数字
        int arr[m];
        for(int i=0;i<m;i++)
        {
            scanf("%d",&arr[i]);
        }


        int pre[m];
        for(int pos=0;pos<m;pos++)
        {
            pre[pos]=sum1(arr,m,pos);
        }
        int suf[m];
        for(int pos=0;pos<m;pos++)
        {
            suf[pos]=sum2(arr,m,pos);
        }
        printf("%d\n",count);
    }
