
#include <stdio.h>
#define max(a,b) (a > b ? a : b)
 
int main()
{
  setbuf(stdin,0);
  int n,arr[110] = {0};
  while(scanf("%d",&n) != EOF)
  {
 
    int sum = 1,fushu = 0,lin = 0;
    for(int i = 0;i < n;++i)
    {
      scanf("%d",&arr[i]);
      if(arr[i] == 0){lin++;}
      if(arr[i] < 0){fushu++;}
      if(arr[i] > 0){sum *= arr[i];}
    }
 
    for(int i = 0;i < n;i++)
    {
      for(int j = 0;j < n - 1;j++)
      {
        if(arr[j] > arr[j + 1])
        {
          int temp = arr[j+1];
          arr[j+1] = arr[j];
          arr[j] = temp;
        }
      }
    }
 
    if(lin == n) {printf("0\n");continue;}
    else if((lin == n - 1) && (fushu == 1)) {printf("0\n");continue;}
 
    if(fushu % 2 == 1)
    {
      for(int i = 0;i < fushu - 1;++i)
      {
        sum *= arr[i];
      }
    }
    else
    {
      for(int i = 0;i < fushu;++i)
      {
        sum *= arr[i];
      }
    }
    printf("%d\n",sum);
  }
  return 0;
}