#include <stdio.h>
// 判断一个数是否为回文数
int huiwen(int a) {
    // 处理负数（题目中可能不涉及，但为了健壮性）
    if (a < 0) {
        return 0;
    }
    
    // 提取数字的每一位
    int digits[10]; // 假设最大不超过10位数
    int count = 0;
    int temp = a;
    
    // 特殊处理0的情况
    if (temp == 0) {
        digits[count++] = 0;
    } else {
        while (temp > 0) {
            digits[count++] = temp % 10;
            temp /= 10;
        }
    }
    
    // 检查回文
    for (int i = 0; i < count / 2; i++) {
        if (digits[i] != digits[count - 1 - i]) {
            return 0;
        }
    }
    return 1;
}








long long int jinzhihuiwen(long long int a)
{
long long int re=a;
long long int arr[10000];
long long int count=0;
for(long long int i=0;i<10000;i++)
{
    arr[i]=0;
}
long long int i=0;
long long int temp=a;
while(re>0)
{
temp=re%2;//17
re=re/2;
arr[i++]=temp;
count+=1;
}
//判断回文数
long long int flag=1;
for(long long int i=0;i<count;i++)
{
    if(arr[i]!=arr[count-1-i]) flag=0;
}
if(flag==1) return 1;
else return 0;
}




int main()
{
    long long int x;
   while(scanf("%lld",&x)!=EOF)
   {
    if(jinzhihuiwen(x)==1||huiwen(x)==1) printf("Yes\n");
    else if(jinzhihuiwen(x)==0&&huiwen(x)==0) printf("No\n");
   }
}   