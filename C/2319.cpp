    #include <stdio.h>
    #include <stdio.h>
    #include <math.h>
    struct Point{
        double result;
        int num;
    };

    //计算组合数 C(n, k) = n!/(k!(n-k)!)
    int C(int n, int k) {
        // 1. 处理非法输入和边界情况
        if (k < 0 || k > n || n < 0) {
            return 0; // 无效输入返回0
        }
        if (k == 0 || k == n) {
            return 1; // C(n,0)=C(n,n)=1
        }

        // 2. 优化：利用 C(n,k) = C(n, n-k)，取较小的k减少计算量
        k = (k < n - k) ? k : n - k;

        // 3. 分步计算（避免直接阶乘，减少溢出概率）
        int result = 1;
        for (int i = 1; i <= k; ++i) {
            // 关键：先乘后除（保证每步结果是整数），但int仍可能溢出
            result = result * (n - k + i) / i;

            // 简单溢出检测（若中间结果为负，说明溢出，直接返回0）
            if (result < 0) {
                return 0;
            }
        }

        return result;
    }





    int main()
    {   int n;
        while(scanf("%d",&n)!=EOF)
        {   
            struct Point points[n+1];
            for(int i=0;i<n+1;i++)
            {   
                scanf("%d",&points[i].num);
            }
        //储存结果在arr_result中
        
        for(int i=0;i<n+1;i++)
        {
            points[i].result=(double)C(n,i)/(double)pow(2,n);
        } 
        int x;
        scanf("%d",&x);
        for(int i=0;i<n+1;i++)
        {
            if(x==points[i].num) printf("%lf\n",points[i].result);
        } 



        }
    }