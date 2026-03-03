#include<stdio.h>
#include<stdlib.h>
//ÎÒÊÇÄã°Ö
typedef struct {
    double ratio;
    int time;
    int value;
} Paper;

int compare(const void *a, const void *b) {
    Paper *p1 = (Paper *)a;
    Paper *p2 = (Paper *)b;
    
    
    if (p1->ratio > p2->ratio) return -1;
    if (p1->ratio < p2->ratio) return 1;
    return 0;
}

int main()
{
    int num = 0;
    int Time = 0;
    
    while(scanf("%d %d", &num, &Time) == 2)
    {
        if (num == 0 && Time == 0) break;
        
        Paper papers[num];
        
        for(int i = 0; i < num; i++)
        {
            int time, value;
            scanf("%d %d", &time, &value);
            
            papers[i].time = time;
            papers[i].value = value;
            
            papers[i].ratio = (double)value / time;

        }
        
        qsort(papers, num, sizeof(Paper), compare);
        
        double remainingtime = Time;
        double totalValue = 0.0;
        
        for(int i = 0; i < num && remainingtime > 0; i++)
        {
            
            if(remainingtime >= papers[i].time)
            {
                remainingtime -= papers[i].time;
                totalValue += papers[i].value;
            }   
            else
            {
                double fraction = (double)remainingtime / papers[i].time;
                totalValue += fraction * papers[i].value;
                break;
            }
        }
        if (totalValue < 0) 
        { 
            totalValue = 0.0;
        }
        
        printf("%.2f\n", totalValue);
    }
    return 0;
}