    #include <stdio.h>
    void swap(int *a,int *b)
    {
        int temp=*a;
        *a=*b;
        *b=temp;
    }
    void * sort(int arr[])
    {                                  //2,3,1
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2-i;j++)
            {
                if(arr[j+1]<arr[j])
                {
                    swap(&arr[j+1],&arr[j]);
                }
            }
        }
    }

    int main()
    {   
        int s;
        scanf("%d",&s);
        //取出6个数字
        
        for(int a=1;a<=s;a++)
        {
            for(int b=a+1;b<=s;b++)
            {
                for(int c=b+1;c<=s;c++)
                {
                    if(a+b+c==s) 
                    {   
                        int sum_sq1=a*a+b*b+c*c;
                        for(int d=a+1;d<=s;d++)
                        {
                            for(int e=d+1;e<=s;e++)
                            {
                                for(int f=e+1;f<=s;f++)
                                {
                                    if(e+d+f==s&&e*e+d*d+f*f==sum_sq1) {
                                        
                                    int arr[3];
                                    arr[0]=d;arr[1]=e;arr[2]=f;
                                    sort(arr);
                                        printf("(%d,%d,%d):",a,b,c);
                                        printf("(%d,%d,%d)",arr[0],arr[1],arr[2]);
                                        printf("\n");
                                }
                            }
                        }
                    }
                }

            }
        }
    }
    }