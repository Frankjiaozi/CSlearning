#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n)!=EOF) 
    {  
        float arr[1000]; 
        for (int i = 0; i < n; i++) 
        {
            scanf("%f", &arr[i]);
        }
        float max = arr[0];
        float min = arr[0];
        for (int i = 1; i < n; i++) 
        { 
            if (arr[i] > max) 
            {
                max = arr[i];
            }
            if (arr[i] < min) 
            {
                min = arr[i];
            }
        }
    int length=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    {
    arr[i]=(arr[i]-min)/(max-min);
    }
    for(int i=0;i<n;i++)
    {
    printf("%.3f ",arr[i]);
    }
    }
    return 0;
}